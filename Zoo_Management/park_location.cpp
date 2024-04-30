#include"park_location.h"

//东门为起点
vector<PII> east_gate={
    make_pair(250,"河流区"),
    make_pair(150,"海洋区"),
    make_pair(500,"热带雨林区"),
    make_pair(450,"温带森林区"),
    make_pair(350,"极地荒漠区")
};

//南门为起点
vector<PII> south_gate={
    make_pair(100,"河流区"),
    make_pair(350,"海洋区"),
    make_pair(200,"热带雨林区"),
    make_pair(300,"温带森林区"),
    make_pair(350,"极地荒漠区")
};

//河流区为起点
vector<PII> river_life_area={
    make_pair(250,"东门"),
    make_pair(100,"南门"),
    make_pair(50,"海洋区"),
    make_pair(50,"热带雨林区"),
    make_pair(75,"温带森林区"),
    make_pair(100,"极地荒漠区")
};

//海洋区为起点
vector<PII> sea_life_area={
    make_pair(150,"东门"),
    make_pair(350,"南门"),
    make_pair(50,"河流区"),
    make_pair(450,"热带雨林区"),
    make_pair(250,"温带森林区"),
    make_pair(100,"极地荒漠区")
};

//极地荒漠区为起点
vector<PII> polar_area={
    make_pair(350,"东门"),
    make_pair(350,"南门"),
    make_pair(350,"河流区"),
    make_pair(100,"海洋区"),
    make_pair(350,"热带雨林区"),
    make_pair(50,"温带森林区"),
};

//温带森林区为起点
vector<PII> temperate_area={
    make_pair(450,"东门"),
    make_pair(300,"南门"),
    make_pair(50,"河流区"),
    make_pair(100,"海洋区"),
    make_pair(50,"热带雨林区"),
    make_pair(50,"极地荒漠区")
};

//热带雨林区为起点
vector<PII> tropical_area={
    make_pair(450,"东门"),
    make_pair(200,"南门"),
    make_pair(50,"河流区"),
    make_pair(450,"海洋区"),
    make_pair(50,"温带森林区"),
    make_pair(350,"极地荒漠区")
};