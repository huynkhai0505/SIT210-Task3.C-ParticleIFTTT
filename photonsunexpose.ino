#define DELAY_TIME 1000

int luminance;
int photon = A4;
bool sun_exposure;
int exposure_period;
int one_hour;
int count_for_one;

void setup() {
    
    Particle.variable("luminance", luminance);
    Particle.variable("photon", photon);
 
    pinMode(luminance,INPUT);
    sun_exposure = false;
    exposure_period= 0;
    one_hour = 10000;
    count_for_one = 1;
}

void loop() {
    luminance = analogRead(photon);
    if(luminance >= 0 && luminance <= 100 && sun_exposure = true){
    Particle.publish("day_status","Terrarium in shade",PRIVATE);
    sun_exposure = false;
    } 
    else {
    Particle.publish("day_status","Terrarium in sunlight",PRIVATE);
    sun_exposure = true;
    exposure_period += DELAY_TIME; 
    }
    if(exposure_period == one_hour*count_for_one){
    Particle.publish("day_status", String(count_for_one),PRIVATE); 
    count_for_one++;
    }
    
    delay(DELAY_TIME); 
    
}