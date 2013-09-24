import ddf.minim.*;
import ddf.minim.signals.*;
import ddf.minim.effects.*;

Minim minim;

ArrayList pts;
ArrayList shapes;

float startTime;
float playbackStart;
float timeInSec;

boolean isRecording;
boolean mute;
boolean trails;

float angle;

void setup() {
  size(1000, 700);
  background(0); 
  frameRate(60);
  colorMode(HSB, 255);

  minim = new Minim(this);


  pts = new ArrayList();
  shapes = new ArrayList();

  startTime = 0;
  playbackStart = 0;
  timeInSec = millis() / 1000;

  isRecording = false;
  mute = false;
  trails = true;
}

void draw() {
  if (trails) {
    fill(0, 30);
  }
  else {
    fill(0);
  }
  rect(0, 0, width, height);

  timeInSec = float(millis()) / 1000.0;

  if (isRecording == true) {
    stroke(50);
  }
  else {
    noStroke();
  }
  noFill();
  beginShape();
  for (int i = 0; i < pts.size(); i++) {
    TimePoint tmp = (TimePoint) pts.get(i);
    vertex(tmp.x, tmp.y);
  }
  endShape();

  for (int i = 0; i < shapes.size(); i++) {
    Shape s = (Shape) shapes.get(i);
    s.update();
    s.display();
  }
  fill(50);
  text("Press 'R' to reset", 10, 20);
  text("Press 'M' to toggle mute", 10, 40);
  text("Press 'T' to toggle trails", 10, 60);
}

void mousePressed() {
  for (int i = pts.size()-1; i >= 0; i--) {
    pts.remove(i);
  }

  isRecording = true;
  startTime = timeInSec;

  pts.add(new TimePoint(mouseX, mouseY, startTime));
}

void mouseDragged() {
  pts.add(new TimePoint(mouseX, mouseY, timeInSec - startTime));
}

void mouseReleased() {
  isRecording = false;
  playbackStart = timeInSec;

  shapes.add(new Shape());

  for (int i = 0; i < pts.size(); i++) {
    Shape last = (Shape) shapes.get(shapes.size() - 1);
    TimePoint tmp = (TimePoint) pts.get(i);
    last.points.add(new TimePoint(tmp.x, tmp.y, tmp.t));
    if (mute) {
      last.out.mute();
    }
  }
}

void keyPressed() {
  if (key == 'r' || key == 'R') {
    for (int i = shapes.size()-1; i >=0; i--) {
      Shape s = (Shape) shapes.get(i);
      s.out.close();
      shapes.remove(i);
    }
  }

  if (key == 't' || key == 'T') {
    trails = !trails;
  }

  if ( key == 'm' )
  {
    if (mute == false) {
      for (int i = 0; i < shapes.size(); i++) {
        Shape s = (Shape) shapes.get(i);
        s.out.mute();
        mute = true;
      }
    }
    else {
      for (int i = 0; i < shapes.size(); i++) {
        Shape s = (Shape) shapes.get(i);
        s.out.unmute();
        mute = false;
      }
    }
  }
}

void stop()
{
  for (int i = 0; i < shapes.size(); i++) {
    Shape s = (Shape) shapes.get(i);
    s.out.close();
  }
  minim.stop();

  super.stop();
}

