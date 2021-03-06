//
// Created by Amelia Chady on 11/27/2018.
// Testing for Sound and SoundMap objects.
//

#include <iostream>
#include "ArraySoundMap.h"
#include "Sound.h"

void testSound(){
    std::cout << "--Sound Tests--------" << std::endl;
    int passes = 0;
    int fails = 0;

    Sound soundA("A");

    //Testing getSymbol
    if(soundA.getSymbol() == "A"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }


    //Testing addConnection (and basic getSimilarSymbol
    Sound soundB("B");
    soundA.addConnection(&soundB);

    if(soundA.getSimilarSymbol() == soundB.getSymbol()) {
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(soundB.getSimilarSymbol() == soundA.getSymbol()){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    Sound soundC("C");

    // Testing Locking
    soundA.lock();

    if(soundA.getLocked()){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    try{
        soundA.addConnection(&soundC);
        std::cout << "failed" << std::endl;
        fails++;
    }catch(std::exception e){
        std::cout << "passed" << std::endl;
        passes++;
    }

    try{
        soundC.addConnection(&soundA);
        std::cout << "failed" << std::endl;
        fails++;
    }catch(std::exception e){
        std::cout << "passed" << std::endl;
        passes++;
    }

    //Testing getSimilarSymbol Error
    Sound soundD("D");
    try{
        soundD.getSimilarSymbol();
        std::cout << "failed" << std::endl;
        fails++;
    }catch(std::out_of_range e){
        std::cout << "passed" << std::endl;
        passes++;
    }

    std::cout << "Overall:" << std::endl;
    std::cout << "Passed " << passes << " times." << std::endl;
    std::cout << "Failed " << fails << " times." << std::endl;
    std::cout << "--Done--------" << std::endl;
}

void testSoundMap(){
    std::cout << "--SoundMap Tests--------" << std::endl;
    int passes = 0;
    int fails = 0;

    try{
        SoundMap* testDefault = new ArraySoundMap();
        testDefault->read();
        std::cout << "passed" << std::endl;
        passes++;
        delete testDefault;
    }catch(std::exception e){
        std::cout << "failed" << std::endl;
        fails++;
    }

    SoundMap* map = new ArraySoundMap("testSounds.txt");

    if(map->getFileName() == "testSounds.txt"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }


    try{
        map->read();
        std::cout << "passed" << std::endl;
        passes++;
    }catch(std::exception e){
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(map->getKey("A")->getSymbol()=="A"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    if(map->getKey("B")->getSymbol()=="B"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    try{
        map->getKey("Z");
        std::cout << "failed" << std::endl;
        fails++;
    }catch(std::invalid_argument e){
        std::cout << "passed" << std::endl;
        passes++;
    }

    if(map->getKey("A")->getSimilarSymbol()=="B"){
        std::cout << "passed" << std::endl;
        passes++;
    }else{
        std::cout << "failed" << std::endl;
        fails++;
    }

    std::cout << "Overall:" << std::endl;
    std::cout << "Passed " << passes << " times." << std::endl;
    std::cout << "Failed " << fails << " times." << std::endl;
    std::cout << "--Done--------" << std::endl;
}

int main(){
    try {
        testSound();
    }catch(std::exception){
        std::cout << "Error while testing class Sound" << std::endl;
    }

    try {
        testSoundMap();
    }catch(std::exception){
        std::cout << "Error while testing class SoundMap" << std::endl;
    }


    return 0;
}