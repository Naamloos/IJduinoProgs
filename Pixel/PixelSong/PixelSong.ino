#include "pitches.h"

// notes in the melody:
int melody1[] = {
  NOTE_D3, NOTE_D3, NOTE_F4, NOTE_D3, NOTE_D3, NOTE_AS4, NOTE_D3, NOTE_D3, NOTE_CS3, NOTE_D3, NOTE_D3, NOTE_F4, NOTE_D3, NOTE_D3, NOTE_AS4, NOTE_B4
};

int melody2[] = {
	NOTE_DS3, NOTE_C5, NOTE_C3
};

int melody3[] = {
	NOTE_AS4, NOTE_G5, 0
};

int noteDurations[] = {
  8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 8, 8, 4, 2
};

int noteDurations2[] = {
	2, 2, 2
};

int noteDurations3[] = {
	2, 6, 2
};

void setup() {
	
	/*for (int thisNote = 0; thisNote < 16; thisNote++) {
	
		// to calculate the note duration, take one second
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / noteDurations[thisNote];
		tone(8, melody1[thisNote], noteDuration);
		
		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(8);
	}*/
}

void loop() {
	  // iterate over the notes of the melody:
	for (int thisNote = 0; thisNote < 16; thisNote++) {
	
		// to calculate the note duration, take one second
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / noteDurations[thisNote];
		tone(8, melody1[thisNote], noteDuration);
		
		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(8);
	}
	for (int thisNote = 0; thisNote < 3; thisNote++) {

		// to calculate the note duration, take one second
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / noteDurations2[thisNote];
		tone(8, melody2[thisNote], noteDuration);
		
		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(8);
	}
	for (int thisNote = 0; thisNote < 16; thisNote++) {
	
		// to calculate the note duration, take one second
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / noteDurations[thisNote];
		tone(8, melody1[thisNote], noteDuration);
		
		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(8);
	}
	for (int thisNote = 0; thisNote < 3; thisNote++) {

		// to calculate the note duration, take one second
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / noteDurations3[thisNote];
		tone(8, melody3[thisNote], noteDuration);
		
		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(8);
	}
}