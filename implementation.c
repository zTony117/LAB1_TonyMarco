#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "utilities.h"  // DO NOT REMOVE this line
#include "implementation_reference.h"   // DO NOT REMOVE this line

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param offset - number of pixels to shift the object in bitmap image up
 * @return - pointer pointing a buffer storing a modified 24-bit bitmap image
 * Note1: White pixels RGB(255,255,255) are treated as background. Object in the image refers to non-white pixels.
 * Note2: You can assume the object will never be moved off the screen
 **********************************************************************************************************************/
unsigned char *processMoveUp(unsigned char *buffer_frame, unsigned width, unsigned height, int offset) {
    return processMoveUpReference(buffer_frame, width, height, offset);
}

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param offset - number of pixels to shift the object in bitmap image left
 * @return - pointer pointing a buffer storing a modified 24-bit bitmap image
 * Note1: White pixels RGB(255,255,255) are treated as background. Object in the image refers to non-white pixels.
 * Note2: You can assume the object will never be moved off the screen
 **********************************************************************************************************************/
unsigned char *processMoveRight(unsigned char *buffer_frame, unsigned width, unsigned height, int offset) {
    return processMoveRightReference(buffer_frame, width, height, offset);
}

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param offset - number of pixels to shift the object in bitmap image up
 * @return - pointer pointing a buffer storing a modified 24-bit bitmap image
 * Note1: White pixels RGB(255,255,255) are treated as background. Object in the image refers to non-white pixels.
 * Note2: You can assume the object will never be moved off the screen
 **********************************************************************************************************************/
unsigned char *processMoveDown(unsigned char *buffer_frame, unsigned width, unsigned height, int offset) {
    return processMoveDownReference(buffer_frame, width, height, offset);
}

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param offset - number of pixels to shift the object in bitmap image right
 * @return - pointer pointing a buffer storing a modified 24-bit bitmap image
 * Note1: White pixels RGB(255,255,255) are treated as background. Object in the image refers to non-white pixels.
 * Note2: You can assume the object will never be moved off the screen
 **********************************************************************************************************************/
unsigned char *processMoveLeft(unsigned char *buffer_frame, unsigned width, unsigned height, int offset) {
    return processMoveLeftReference(buffer_frame, width, height, offset);
}

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param rotate_iteration - rotate object inside frame buffer clockwise by 90 degrees, <iteration> times
 * @return - pointer pointing a buffer storing a modified 24-bit bitmap image
 * Note: You can assume the frame will always be square and you will be rotating the entire image
 **********************************************************************************************************************/
unsigned char *processRotateCW(unsigned char *buffer_frame, unsigned width, unsigned height,
                               int rotate_iteration) {
    return processRotateCWReference(buffer_frame, width, height, rotate_iteration);
}

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param rotate_iteration - rotate object inside frame buffer counter clockwise by 90 degrees, <iteration> times
 * @return - pointer pointing a buffer storing a modified 24-bit bitmap image
 * Note: You can assume the frame will always be square and you will be rotating the entire image
 **********************************************************************************************************************/
unsigned char *processRotateCCW(unsigned char *buffer_frame, unsigned width, unsigned height,
                                int rotate_iteration) {
    return processRotateCCWReference(buffer_frame, width, height, rotate_iteration);
}

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param _unused - this field is unused
 * @return
 **********************************************************************************************************************/
unsigned char *processMirrorX(unsigned char *buffer_frame, unsigned int width, unsigned int height, int _unused) {
    return processMirrorXReference(buffer_frame, width, height, _unused);
}

/***********************************************************************************************************************
 * @param buffer_frame - pointer pointing to a buffer storing the imported 24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param _unused - this field is unused
 * @return
 **********************************************************************************************************************/
unsigned char *processMirrorY(unsigned char *buffer_frame, unsigned width, unsigned height, int _unused) {
    return processMirrorYReference(buffer_frame, width, height, _unused);
}

unsigned char *doTranslations(unsigned char *frame_buffer, unsigned width, unsigned height, int vertical_movement, int horizontal_movement) {
    if (vertical_movement > 0) {
        frame_buffer = processMoveUp(frame_buffer, width, height, vertical_movement);
        vertical_movement = 0;
                //printBMP(width, height, frame_buffer);
    }

    else if (vertical_movement < 0) {
        frame_buffer = processMoveDown(frame_buffer, width, height, -vertical_movement);
        vertical_movement = 0;
                //printBMP(width, height, frame_buffer);
    }

    if (horizontal_movement > 0) {
        frame_buffer = processMoveRight(frame_buffer, width, height, horizontal_movement);
        horizontal_movement = 0;
                //printBMP(width, height, frame_buffer);
    }

    else if (horizontal_movement < 0) {
        frame_buffer = processMoveLeft(frame_buffer, width, height, -horizontal_movement);
        horizontal_movement = 0;
                //printBMP(width, height, frame_buffer);
    }

    return frame_buffer;
}



/***********************************************************************************************************************
 * WARNING: Do not modify the implementation_driver and team info prototype (name, parameter, return value) !!!
 *          Do not forget to modify the team_name and team member information !!!
 **********************************************************************************************************************/
void print_team_info(){
    // Please modify this field with something interesting
    char team_name[] = "OH NO";

    // Please fill in your information
    char student1_first_name[] = "Zhaotong";
    char student1_last_name[] = "Zheng";
    char student1_student_number[] = "1001651152";

    // Please fill in your partner's information
    // If yon't have partner, do not modify this
    char student2_first_name[] = "Yue Hin";
    char student2_last_name[] = "Lau";
    char student2_student_number[] = "1001408069";

    // Printing out team information
    printf("*******************************************************************************************************\n");
    printf("Team Information:\n");
    printf("\tteam_name: %s\n", team_name);
    printf("\tstudent1_first_name: %s\n", student1_first_name);
    printf("\tstudent1_last_name: %s\n", student1_last_name);
    printf("\tstudent1_student_number: %s\n", student1_student_number);
    printf("\tstudent2_first_name: %s\n", student2_first_name);
    printf("\tstudent2_last_name: %s\n", student2_last_name);
    printf("\tstudent2_student_number: %s\n", student2_student_number);
}

/***********************************************************************************************************************
 * WARNING: Do not modify the implementation_driver and team info prototype (name, parameter, return value) !!!
 *          You can modify anything else in this file
 ***********************************************************************************************************************
 * @param sensor_values - structure stores parsed key value pairs of program instructions
 * @param sensor_values_count - number of valid sensor values parsed from sensor log file or commandline console
 * @param frame_buffer - pointer pointing to a buffer storing the imported  24-bit bitmap image
 * @param width - width of the imported 24-bit bitmap image
 * @param height - height of the imported 24-bit bitmap image
 * @param grading_mode - turns off verification and turn on instrumentation
 ***********************************************************************************************************************
 *
 **********************************************************************************************************************/
void implementation_driver(struct kv *sensor_values, int sensor_values_count, unsigned char *frame_buffer,
                           unsigned int width, unsigned int height, bool grading_mode) {
    int processed_frames = 0;

    //added variables to store stuff
    int horizontal_movement = 0;
	int vertical_movement = 0;
    int rotation_clockwise = 0;
    int mirrorX = 0;
    int mirrorY = 0;

    int mod25_frames = 0;

    //Accumulate sensor values if they are translations
    //If rotation or mirror, accumulate if next instruction is the same, otherwise immediately process rotation or mirror
    for (int sensorValueIdx = 0; sensorValueIdx < sensor_values_count; sensorValueIdx++) {
        processed_frames += 1;
        mod25_frames = processed_frames % 25;
//        printf("Processing sensor value #%d: %s, %d\n", sensorValueIdx, sensor_values[sensorValueIdx].key,
//               sensor_values[sensorValueIdx].value);
        if (!strcmp(sensor_values[sensorValueIdx].key, "W")) {
            vertical_movement += sensor_values[sensorValueIdx].value;
//            printBMP(width, height, frame_buffer);
        } 

        else if (!strcmp(sensor_values[sensorValueIdx].key, "A")) {
            horizontal_movement -= sensor_values[sensorValueIdx].value;
//            printBMP(width, height, frame_buffer);
        } 

        else if (!strcmp(sensor_values[sensorValueIdx].key, "S")) {
             vertical_movement -= sensor_values[sensorValueIdx].value;
//            printBMP(width, height, frame_buffer);
        } 

        else if (!strcmp(sensor_values[sensorValueIdx].key, "D")) {
            horizontal_movement += sensor_values[sensorValueIdx].value;
//            printBMP(width, height, frame_buffer);
        } 
        
        //if clockwise rotation, accumulate if next instruction is rotation
        else if (!strcmp(sensor_values[sensorValueIdx].key, "CW")) {
            rotation_clockwise += sensor_values[sensorValueIdx].value;

            //if need to verify frames, process previous translations, and do the rotation
            if (mod25_frames == 0 && rotation_clockwise != 0) {
                int trueRotation = rotation_clockwise % 4;

                if (trueRotation != 0) {

                    if (vertical_movement != 0 || horizontal_movement != 0) {
                        doTranslations(frame_buffer, width, height, vertical_movement, horizontal_movement);
                        vertical_movement = 0;
                        horizontal_movement = 0;
                    }

                    if (rotation_clockwise > 0)
                        frame_buffer = processRotateCW(frame_buffer, width, height, trueRotation);
                    else 
                        frame_buffer = processRotateCCW(frame_buffer, width, height, -trueRotation);
                    rotation_clockwise = 0;
                }
            }

            else {
                //POTENTIAL FOR OPTIMIZATION HERE. ALREADY CHECKING NEXT VALUE. MIGHT AS WELL SKIP IT. JUST ADD +2 TO COUNTER INSTEAD OF +1 IF THE SAME AND ACCUMULATE NEXT VALUE
                if (!strcmp(sensor_values[sensorValueIdx + 1].key, "CW") || !strcmp(sensor_values[sensorValueIdx + 1].key, "CCW")) {
                    //do nothing
                }
                else if (rotation_clockwise != 0) {
                    int trueRotation = rotation_clockwise % 4;

                    if (trueRotation != 0) {

                        if (vertical_movement != 0 || horizontal_movement != 0) {
                            doTranslations(frame_buffer, width, height, vertical_movement, horizontal_movement);
                            vertical_movement = 0;
                            horizontal_movement = 0;
                        }

                        if (rotation_clockwise > 0)
                            frame_buffer = processRotateCW(frame_buffer, width, height, trueRotation);
                        else 
                            frame_buffer = processRotateCCW(frame_buffer, width, height, -trueRotation);
                        rotation_clockwise = 0;
                    }
                }
            }
        }
//            printBMP(width, height, frame_buffer);
        else if (!strcmp(sensor_values[sensorValueIdx].key, "CCW")) {
            rotation_clockwise = rotation_clockwise - sensor_values[sensorValueIdx].value;

            //if need to verify frames, process previous translations, and do the rotation
            if (mod25_frames == 0 && rotation_clockwise != 0) {
                int trueRotation = rotation_clockwise % 4;

                if (trueRotation != 0) {

                    if (vertical_movement != 0 || horizontal_movement != 0) {
                        doTranslations(frame_buffer, width, height, vertical_movement, horizontal_movement);
                        vertical_movement = 0;
                        horizontal_movement = 0;
                    }

                    if (rotation_clockwise > 0)
                        frame_buffer = processRotateCW(frame_buffer, width, height, trueRotation);
                    else 
                        frame_buffer = processRotateCCW(frame_buffer, width, height, -trueRotation);
                    rotation_clockwise = 0;
                }
            }

            else {
                //POTENTIAL FOR OPTIMIZATION HERE. ALREADY CHECKING NEXT VALUE. MIGHT AS WELL SKIP IT. JUST ADD +2 TO COUNTER INSTEAD OF +1 IF THE SAME AND ACCUMULATE NEXT VALUE
                if (!strcmp(sensor_values[sensorValueIdx + 1].key, "CW") || !strcmp(sensor_values[sensorValueIdx + 1].key, "CCW")) {
                    //do nothing
                }
                else if (rotation_clockwise != 0) {
                    int trueRotation = rotation_clockwise % 4;

                    if (trueRotation != 0) {

                        if (vertical_movement != 0 || horizontal_movement != 0) {
                            doTranslations(frame_buffer, width, height, vertical_movement, horizontal_movement);
                            vertical_movement = 0;
                            horizontal_movement = 0;
                        }

                        if (rotation_clockwise > 0)
                            frame_buffer = processRotateCW(frame_buffer, width, height, trueRotation);
                        else 
                            frame_buffer = processRotateCCW(frame_buffer, width, height, -trueRotation);
                        rotation_clockwise = 0;
                    }
                }
            }
        }

        else if (!strcmp(sensor_values[sensorValueIdx].key, "MX")) {

            mirrorX++;

            if (!strcmp(sensor_values[sensorValueIdx + 1].key, "MX") && mod25_frames != 0) {
                //do nothing
            }

            else if (mirrorX %2 != 0) {
                if (vertical_movement != 0 || horizontal_movement != 0) {
                    doTranslations(frame_buffer, width, height, vertical_movement, horizontal_movement);
                    vertical_movement = 0;
                    horizontal_movement = 0;
                }

                frame_buffer = processMirrorX(frame_buffer, width, height, 1);
                mirrorX = 0;
            }
//            printBMP(width, height, frame_buffer);
        } 

        else if (!strcmp(sensor_values[sensorValueIdx].key, "MY")) {

            mirrorY++;

            if (!strcmp(sensor_values[sensorValueIdx + 1].key, "MY") && mod25_frames != 0) {
                //do nothing
            }

            else if (mirrorY %2 != 0) {
                if (vertical_movement != 0 || horizontal_movement != 0) {
                    doTranslations(frame_buffer, width, height, vertical_movement, horizontal_movement);
                    vertical_movement = 0;
                    horizontal_movement = 0;
                }

                frame_buffer = processMirrorY(frame_buffer, width, height, 1);
                mirrorY = 0;
            }
//            printBMP(width, height, frame_buffer);
        }

        //processed_frames += 1;

        //Process every 25 frames regardless of sensor value
        if (mod25_frames == 0) {

            //translations
            if (vertical_movement != 0 || horizontal_movement != 0) {
                    doTranslations(frame_buffer, width, height, vertical_movement, horizontal_movement);
                    vertical_movement = 0;
                    horizontal_movement = 0;
            }

            verifyFrame(frame_buffer, width, height, grading_mode);        
        }
    }
    return;
}