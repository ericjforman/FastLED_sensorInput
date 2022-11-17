# FastLED_sensorInput
Shows a single pixel moving in response to sensor input. A simple scrolling animation plays continuously behind it, without delaying the main loop. 

This demonstrates the use of one of FastLED's internal timer functions as opposed to using a standard delay(), which also delays everyting else such as reading a sensor. In this case rather than setting the animation speed using delay(N), instead it updates the animation every N milliseconds. 
