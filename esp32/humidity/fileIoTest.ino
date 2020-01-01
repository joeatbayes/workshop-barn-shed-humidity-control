
void testFileIO() {
 if(!SPIFFS.begin(true)){
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
   }

  /* Comment out because we do not want to wear
     *  out our strorage
     
    File file = SPIFFS.open("/test.txt", FILE_WRITE);
 
    if(!file){
        Serial.println("There was an error opening the file for writing");
        return;
    }
 
    if(file.print("TEST")){
        Serial.println("File was written");;
    } else {
        Serial.println("File write failed");
    }
 
    file.close();
    */

    // Read a file in a directory
    File file2 = SPIFFS.open("/test.txt");
    if(!file2){
        Serial.println("Failed to open file for reading");
        return;
    }
    Serial.println("File Content:");
    // print content from the file
    while(file2.available()){
        Serial.write(file2.read());
    }
    file2.close();



  // List Files Available in Directory
  File root = SPIFFS.open("/");
  File file3 = root.openNextFile();
  while(file3){
      Serial.print("FILE: ");
      Serial.println(file3.name());
      file3 = root.openNextFile();
  }
  // Wait a while to do anything else.

}
