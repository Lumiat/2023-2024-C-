/*啊哈，这个为之前写的有点问题的分类写的参考，现在把tourist_service干脆改成permission_manage
的派生了，逻辑已经不太对了，但是里面实现的具体方式需要可以参考一下
老规矩：上链接 https://www.dotcpp.com/run/16632373 */
#include <iostream>
#include <string>
#include <vector>

// 动物结构体
struct Animal {
    std::string name;
    std::string species;
    std::string location;
};

// 动物园区基类
class Animal_Manage {
public:
    virtual std::string getAnimalLocation(const std::string& animalName) = 0;
    virtual std::string getAnimalCata(const std::string& animalName)=0;
};

// 水生区类
class Aqua_Area : public Animal_Manage {
private:
    std::vector<Animal> contain;
public:
    void add_animal(const std::string& animalName,const std::string& animalSpecies,const std::string& animalLocation) {
        contain.push_back({animalName,animalSpecies,animalLocation});
    }
    std::string getAnimalLocation(const std::string& animalName) {
        for (const auto& animal : contain) {
            if (animal.name == animalName) {
                return animal.location;
            }
        }
        return "Animal not found in Aqua Area.";
    }
    std::string getAnimalCata(const std::string& animalName){
        for(const auto&animal:contain){
            if(animal.name==animalName) return animal.species;
        }
        return "Animal not found in Aqua Area.";
    }
};

// 陆生区类
class Land_Area : public Animal_Manage {
private:
    std::vector<Animal> contain;
public:
    void add_animal(const std::string& animalName,const std::string& animalSpecies,const std::string& animalLocation) {
        contain.push_back({animalName,animalSpecies,animalLocation});
        
    }
    std::string getAnimalLocation(const std::string& animalName)  {
        for (const auto& animal : contain) {
            if (animal.name == animalName) {
                return animal.location;
            }
        }
        return "Animal not found in Land Area.";
    }
    std::string getAnimalCata(const std::string& animalName){
        for(const auto&animal:contain){
            if(animal.name==animalName) return animal.species;
        }
        return "Animal not found in Land Area.";
    }
};

// 游客服务类
class Tourist_Service {
private:
    std::vector<Animal_Manage*> areas;

public:
    Tourist_Service(std::vector<Animal_Manage*>& areas) : areas(areas) {}

    std::string getAnimalLocation(const std::string& animalName) {
        for (auto area : areas) {
            std::string location = area->getAnimalLocation(animalName);
            if (location != "Animal not found in Aqua Area." && location != "Animal not found in Land Area.") {
                return location;
            }
        }
        return "Animal not found in any area.";
    }
    
    std::string getAnimalCata(const std::string& animalName){
        for (auto area : areas) {
            std::string catagory = area->getAnimalCata(animalName);
            if (catagory != "Animal not found in Aqua Area." && catagory != "Animal not found in Land Area.") {
                return catagory;
            }
        }
        return "Animal not found in any area.";
    }
};

int main() {
    // 创建水生区对象和陆生区对象
    Aqua_Area river_life_area;
    Aqua_Area sea_life_area;
    Land_Area tropical_area;
    Land_Area temperate_area;

    // 添加动物信息
    river_life_area.add_animal("goldfish","fish","river_life_area");
    sea_life_area.add_animal("shark","fish","sea_life_area");
    sea_life_area.add_animal("sperm-whale","mammal","sea_life_area");
    tropical_area.add_animal("parrot","bird","tropical_area");
    temperate_area.add_animal("panda","mammal","temperate_area");

    // 将派生类对象存储在容器中
    std::vector<Animal_Manage*> areas = {&river_life_area, &sea_life_area,&tropical_area,&temperate_area};

    // 创建游客服务对象
    Tourist_Service tourist_service(areas);

    // 获取动物位置信息
    std::cout << "Location of Fish: " << tourist_service.getAnimalLocation("Fish") << std::endl;
    std::cout << "Location of Tiger: " << tourist_service.getAnimalLocation("Tiger") << std::endl;
    std::cout << "Location of Giraffe: " << tourist_service.getAnimalLocation("Giraffe") << std::endl;
    std::cout<<"Location of goldfish: "<<tourist_service.getAnimalLocation("goldfish") << std::endl;
    std::cout<<"Location of shark: "<<tourist_service.getAnimalLocation("shark") << std::endl;
    std::cout<<"Location of sperm-whale: "<<tourist_service.getAnimalLocation("sperm-whale")<<std::endl;
    std::cout<<"Catagory of sperm-whale: "<<tourist_service.getAnimalCata("sperm-whale")<<std::endl;
    std::cout<<"Catagory of shark: "<<tourist_service.getAnimalCata("shark")<<std::endl;
    return 0;
}
