# Thesis - Tracking of selected regions in a video
## Thesis topic:
Creating an application that tracks a user-selected shape in a video in approximately real time, it is a so-called short-term tracker. The application waits for an image of a camera as input. It keeps displaying. If the user chooses to click one within the image, the algorithm uses some region detector to select the image region around the click. Here I try different region detectors, examining which ones are best suited to the problem. The program then tries to track the selected region across multiple frames so that the camera is unstable and presumably moving. It selectively visually marks the selection in the image in some way and notifies the user if the region can no longer be tracked, for example, due to a large change in perspective, or if the observed 3D object is no longer visible in the video.
The program basically uses a package used for image processing called OpenCV written in C ++. The program is designed for the Linux operating system to make it easier to integrate into open-source video streamer applications later.
## Dissertation specification:
https://drive.google.com/file/d/1z8HM0vBniJZOqJRLHPU5VfRXejRxj3_c/view?usp=sharing


# Szakdolgozat - Kijelölt régiók automatikus követése videón
## A dolgozat témája: 
Egy olyan alkalmazás elkészítése, amely egy videón megközelítőleg valós időben egy felhasználó által kijelölt alakzat követését valósítja meg, ún. short-term tracker. Az alkalmazás inputként egy kamera képét várja. Azt folyamatosan megjeleníti. Amennyiben úgy dönt a felhasználó, hogy kattint egyet a képen belül, akkor az algoritmus valamilyen régió-detektor felhasználásával kijelöli a kattintás körüli képi régiót. Itt kipróbálok különböző régió-detektorokat, azt vizsgálva, hogy melyek a legalkalmasabbak a problémára. A program ezután megpróbálja a kijelölt régiót követni több framen keresztül úgy, hogy a kamera közben instabil és feltehetőleg mozog. A kijelölést valamilyen módon folyamatosan vizuálisan jelöli a képen és értesíti a felhasználót, amennyiben a régió nem követhető a továbbiakban, például, nagy perspektíva változás miatt, vagy ha a megfigyelt 3D-s objektum a továbbiakban nem látható a videón.
A program alapvetően egy C++ nyelven írt OpenCV nevű képfeldolgozásra használt csomagot használ. A program Linux operációs rendszerre készül, hogy könnyebb legyen később beilleszteni open-source video streamer alkalmazásokba.
## A dolgozat specifikációja:
https://drive.google.com/file/d/1z8HM0vBniJZOqJRLHPU5VfRXejRxj3_c/view?usp=sharing
