#include <stdio.h>
#include "iflytek_speech_recognition/tinyxml2.h"

using namespace tinyxml2;
int tinyxmlTest(void);

int main(int argc, char* argv[])
{
    tinyxmlTest();
    return 1;
}

int tinyxmlTest(void)
{
    char* xmlStr = "\
<?xml version='1.0' encoding='utf-8' standalone='yes' ?>\
<nlp>\
  <version>1.1</version>\
  <rawtext>打丁伟</rawtext>\
  <confidence>28</confidence>\
  <engine>local</engine>\
  <result>\
    <focus>dialpre|contact</focus>\
    <confidence>0|80</confidence>\
    <object>\
      <dialpre id=\"10001\">打</dialpre>\
      <contact id=\"0\">丁伟</contact>\
    </object>\
  </result>\
</nlp>";
    XMLDocument xmlDoc;
    printf("Parse strings: %s\n", xmlStr);
    xmlDoc.Parse(xmlStr);
        
    XMLNode* root = xmlDoc.RootElement();
    if (root == nullptr) {
      printf("%s %d :Failed to parse the XML string:%s,The root element cannot be found.\n", \
        __FUNCTION__, __LINE__,xmlStr);
      exit(0);
    }
    XMLElement *node = nullptr;
    XMLElement *childNode = nullptr;
    const char *node1AttId = nullptr;

    node = root->FirstChildElement("version");
    const char* value = node->GetText();
    printf("version: %s\n",value);
    
    node=node->NextSiblingElement();
    node = root->FirstChildElement("rawtext");
    value = node->GetText();
    printf("rawtext: %s\n",value);
    
    node=node->NextSiblingElement();
    node = root->FirstChildElement("confidence");
    value = node->GetText();
    printf("confidence: %s\n",value);
    
    node=node->NextSiblingElement();
    node = root->FirstChildElement("engine");
    value = node->GetText();
    printf("engine: %s\n",value);
    
    node=node->NextSiblingElement();
    node = root->FirstChildElement("result");
    
    childNode = node->FirstChildElement("focus");
    value = childNode->GetText();
    printf("focus: %s\n",value);
    
    childNode=childNode->NextSiblingElement();
    childNode = node->FirstChildElement("confidence");
    value = childNode->GetText();
    printf("confidence: %s\n",value);
    
    return 1;
}
