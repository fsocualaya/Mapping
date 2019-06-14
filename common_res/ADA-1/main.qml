import QtQuick 2.11
import QtQuick.Window 2.11
import QtPositioning 5.11
import QtLocation 5.11


Window {
    visible: true
    width: 1280
    height: 720
    title: qsTr("ADA-Proyect")
    Plugin{
        id:map
        name: "osm"

    }

    Map{
        plugin:map
         anchors.fill: parent
         zoomLevel: 13

//         center:Position.coordinate

        }
    }

