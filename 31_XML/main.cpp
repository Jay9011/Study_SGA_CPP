#include <iostream>
#include "XML.h"
using namespace std;
/*
*   XML : eXtensible Markup Language
* 
*   데이터 전송을 위한 언어
* 
*/
void Save()
{
    // xml 요소 생성
    XmlDocument* document = new XmlDocument;

    XmlElement* character = document->NewElement("Character");
    character->SetAttribute("ImagePath", "Textures/mario_all.png");
    document->InsertFirstChild(character);
    
    XmlElement* action = document->NewElement("Action2");
    action->SetAttribute("Type", 0);
    character->InsertFirstChild(action);

    XmlElement* frame = document->NewElement("Frame");
    frame->SetAttribute("x", 100);
    frame->SetAttribute("y", 200);
    frame->SetAttribute("w", 300);
    frame->SetAttribute("h", 400);
    action->InsertFirstChild(frame);

    action = document->NewElement("Action");
    action->SetAttribute("Type", 1);
    character->InsertFirstChild(action);
    frame = document->NewElement("Frame");
    frame->SetAttribute("x", 200);
    frame->SetAttribute("y", 300);
    frame->SetAttribute("w", 400);
    frame->SetAttribute("h", 400);
    action->InsertFirstChild(frame);

    // xml 저장
    document->SaveFile("Image.xml");
    delete document;
}

void Load()
{
    // xml 불러오기
    XmlDocument* document = new XmlDocument;
    document->LoadFile("Image.xml");

    XmlElement* character = document->FirstChildElement();

    const char* path = character->Attribute("ImagePath");
    const char* type = character->FirstChildElement()->Attribute("Type");
    const char* x = character->FirstChildElement("Action2")->FirstChildElement("Frame")->Attribute("x");

    cout << path << endl;
    cout << type << endl;
    cout << x << endl;
}

int main()
{
    Save();
    Load();
}