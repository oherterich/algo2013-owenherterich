class Shape {

  ArrayList points; //holds all of our time points
  float playStart; //when the animation begins
  float theta; //used to store the rotation of the shape

  PVector position; //position of the shape
  PVector velocity; //velocity of the shape

  float stretchX; //distorts shape based on x velocity
  float stretchY; //distorts shape based on y velocity

  color c; //color of shape

  AudioOutput out; //used for shape to make sound
  SineWave sound; //actual wave to create sound

    Shape() {
    points = new ArrayList();
    playStart = timeInSec;

    c = color(random(255), 255, 255);

    // get a stereo line out with a sample buffer of 512 samples
    out = minim.getLineOut(Minim.STEREO, 512);

    // create a SineWave with a frequency of 440 Hz, 
    // an amplitude of 1 and the same sample rate as out
    sound = new SineWave(440, 1, 44100);
    sound.setAmp(0);
    
    //add wave to output
    out.addSignal(sound);
  }

  void update() {
    position = getPositionForTime(timeInSec - playStart);
    velocity = getVelocityForTime(timeInSec - playStart);
    stretchX = map(velocity.x, 5, 50, 20, 40);
    stretchY = map(velocity.y, 5, 50, 20, 40);
    
    float freq = map(position.x, 0, width, 200, 800);
    float volume = map(position.y, 0, height, 0.5, 0);
    sound.setFreq(freq);
    sound.setAmp(volume);
  }

  void display() {
    pushMatrix();
    translate(position.x, position.y);
    rotate(theta);
    fill(c);
    ellipse(0, 0, stretchX, stretchY);
    popMatrix();
  }

  //This function returns the position for any given time.
  PVector getPositionForTime( float time ) {
    PVector pos = new PVector(-1000, -1000);

    if (points.size() < 2) {
      return new PVector(-1000, -1000);
    }

    TimePoint last = (TimePoint) points.get(points.size()-1);
    while (time > last.t) {
      time -= last.t;
    }

    for (int i = 0; i < points.size()-1; i++) {
      TimePoint p1 = (TimePoint) points.get(i);
      TimePoint p2 = (TimePoint) points.get(i+1);

      if (time > p1.t && time < p2.t) {
        float part = time - p1.t;
        float whole = p2.t - p1.t;
        float pct = part / whole;

        pos.x = (1-pct) * p1.x + (pct) * p2.x;
        pos.y = (1-pct) * p1.y + (pct) * p2.y;

        theta = atan2(p2.y - p1.y, p2.x - p1.x) + PI;
      }
    }

    return pos;
  }


  //This function returns the velocity for any given time.
  PVector getVelocityForTime( float time ) {

    PVector vel = new PVector(0, 0);

    if (points.size() < 2) {
      return new PVector(0, 0);
    }

    TimePoint last = (TimePoint) points.get(points.size()-1);
    while (time > last.t) {
      time -= last.t;
    }

    for (int i = 0; i < points.size()-1; i++) {
      TimePoint p1 = (TimePoint) points.get(i);
      TimePoint p2 = (TimePoint) points.get(i+1);

      if (time > p1.t && time < p2.t) {
        vel.x = abs(p2.x - p1.x);
        vel.y = abs(p2.y - p1.y) * -1;
      }
    }

    return vel;
  }
}

