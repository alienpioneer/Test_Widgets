import QtQuick 2.0

Item {
    id: semicircle
    x:0
    y:0
    width: 100
    height: 200
    clip: true

    Rectangle {
         width: parent.width*2
         height: parent.height
         color: "#00ffffff"
         border.color: "black"
         border.width: 1
         radius: width*0.5

    }
}
