#include "object_manager.h"
#include <list>

// Include the Object header files here
#include "skybox.h"
#include "pavement.h"
#include "dark_pavement.h"
#include "dirt.h"
#include "bike_rack.h"
#include "can.h"
// House objects
#include "other_floor.h"
#include "ground_floor.h"
#include "roof.h"
#include "elevation.h"
// Fence objects
#include "fencepost.h"
#include "fence_board.h"
// Lamp objects
#include "lamppost.h"
#include "lamplight.h"
// Bike objects
#include "bike_frame.h"
#include "wheel.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

std::vector<Object*> ObjectManager::GetObjects()
{
    return objects;
}

// This is the creation of the world
// Here we define all the models
void ObjectManager::InitWorld()
{
    Object* skybox = new Skybox();
    skybox->Scale(50);
    skybox->Position(10, 0, 30);
    skybox->Rotate(0, 0, 180);
    objects.push_back(skybox);

    std::vector<Object*>* bike1 = CreateBike(19, 20);
    objects.insert(objects.end(), bike1->begin(), bike1->end());

    std::vector<Object*>* bikerack1 = CreateBikeRacks(23, 12);
    objects.insert(objects.end(), bikerack1->begin(), bikerack1->end());

    std::vector<Object*>* bikerack2 = CreateBikeRacks(10, 28);
    objects.insert(objects.end(), bikerack2->begin(), bikerack2->end());
    
    std::vector<Object*>* fence1 = CreateFence(22, 26, 0, 4);
    objects.insert(objects.end(), fence1->begin(), fence1->end());

    std::vector<Object*>* fence2 = CreateFence(22, 30, 8, 12);
    objects.insert(objects.end(), fence2->begin(), fence2->end());

    std::vector<Object*>* fence3 = CreateFence(22, 26, 20, 24);
    objects.insert(objects.end(), fence3->begin(), fence3->end());

    std::vector<Object*>* fence4 = CreateFence(8, 12, 0, 8);
    objects.insert(objects.end(), fence4->begin(), fence4->end());

    std::vector<Object*>* fence5 = CreateFence(8, 12, 24, 28);
    objects.insert(objects.end(), fence5->begin(), fence5->end());

    std::vector<Object*>* fence6 = CreateFence(8, 12, 36, 40);
    objects.insert(objects.end(), fence6->begin(), fence6->end());

    std::vector<Object*>* floor = CreateFloor();
    objects.insert(objects.end(), floor->begin(), floor->end());

    std::vector<Object*>* house = CreateHouse(40, 19);
    objects.insert(objects.end(), house->begin(), house->end());

    std::vector<Object*>* lamp1 = CreateLamp(23, 21);
    objects.insert(objects.end(), lamp1->begin(), lamp1->end());

    std::vector<Object*>* lamp2 = CreateLamp(9, 5);
    objects.insert(objects.end(), lamp2->begin(), lamp2->end());

    std::vector<Object*>* lamp3 = CreateLamp(9, 25);
    objects.insert(objects.end(), lamp3->begin(), lamp3->end());

    std::vector<Object*>* other = CreateOther();
    objects.insert(objects.end(), other->begin(), other->end());
}

std::vector<Object*>* ObjectManager::CreateBike(float x, float z)
{
    vector<Object*>* bike = new vector<Object*>();

    Object* bike_frame = new BikeFrame();
    bike_frame->Position(x, 0.5f, z);
    bike->push_back(bike_frame);

    for (int i = 0; i < 2; i++) {
        Object* bike_wheel = new Wheel();
        bike_wheel->Position(x, 0.5f, (z - 1.3f) + (2.2f * i));
        bike->push_back(bike_wheel);
    }

    return bike;
}

std::vector<Object*>* ObjectManager::CreateBikeRacks(float x, float z)
{
    vector<Object*>* bikeracks = new vector<Object*>();

    for (int i = 0; i < 5; i++) {
        if (i != 2) {
            Object* bike_rack = new BikeRack();
            bike_rack->Scale(1.5f);
            bike_rack->Rotate(0, 90, 0);
            bike_rack->Position(x, 0.0f, (z + (1.5f * i)));
            bikeracks->push_back(bike_rack);
        }
    }

    return bikeracks;
}

vector<Object*>* ObjectManager::CreateFence(float xMin, float xMax, float zMin, float zMax)
{
    vector<Object*>* fence = new vector<Object*>();
    // First we check the size of the box on both sides
    const float xSide = xMax - xMin;
    const float zSide = zMax - zMin;
    // Now we put all the cords in an array
    const float cords[4][2]{
        {xMin, zMin},
        {xMin, zMax},
        {xMax, zMin},
        {xMax, zMax}
    };

    for (int i = 0; i < 4; i++) {
        // Create all the fenceposts
        Object* fence_post = new Fencepost();
        fence_post->Position(cords[i][0] - 1, 0.5, cords[i][1] - 1);
        fence_post->Scale(0.1, 0.5, 0.1);
        fence->push_back(fence_post);

        // Create the fenceboards
        for (int j = 0; j < zSide; j += 2) {
            if (!(i % 2)) {
                Object* fence_board2 = new FenceBoard();
                fence_board2->Position(cords[i][0] - 1.0, 0.875, cords[i][1] + j);
                fence_board2->Scale(0.05, 0.1, 1);
                fence->push_back(fence_board2);
            }
        }
        for (int j = 0; j < xSide; j += 2) {
            if (i < 2) {
                Object* fence_board1 = new FenceBoard();
                fence_board1->Position(cords[i][0] + j, 0.875, cords[i][1] - 1);
                fence_board1->Scale(0.05, 0.1, 1);
                fence_board1->Rotate(0, 90, 0);
                fence->push_back(fence_board1);
            }
        }
    }
    return fence;
}

std::vector<Object*>* ObjectManager::CreateFloor()
{
    vector<Object*>* floor_tiles = new vector<Object*>();

    // Create the floor based on a two dimensional array from the header
    for (int z = 0; z < sizeof(floor) / sizeof(floor[0]); z++)
        for (int x = 0; x < sizeof(floor[0]) / sizeof(int); x++)
        {
            Object* tile = nullptr;

            switch (floor[z][x])
            {
            case 0: tile = new Pavement(); break;
            case 1: tile = new DarkPavement(); break;
            case 2: tile = new Dirt(); break;
            }

            tile->Position(x * 2.0f, 0, z * 2.0f);
            floor_tiles->push_back(tile);
        }

    return floor_tiles;
}

vector<Object*>* ObjectManager::CreateHouse(float x, float z)
{
    vector<Object*>* house = new vector<Object*>();

    Object* placeholder;
    int widthMax = 12;
    int quarterWidth = widthMax / 4;
    // The boxes are 2 by 2 meaning we only need to place it on every other coordinate
    for (int width = 0; width < widthMax; width += 2)
    {
        // Generate the elevation where the dog sits on top
        if (width >= quarterWidth && width < (widthMax - quarterWidth) - 1) {
            placeholder = new Elevation();
            placeholder->Position(x - 8, 4.5, z + width);
            placeholder->Scale(1, 0.5, 1);
            house->push_back(placeholder);
        }

        // Height of the building
        // Here are, again, used steps of 2 because of the cube size
        for (int height = 1; height < 18; height += 2)
        {
            // Use depth to make the other walls
            for (int depth = -6; depth <= 6; depth += 2)
            {
                if (depth > -6 && depth < 6) {
                    if (width == 0 || width >= (widthMax - 2)) {
                        if (height < 6)
                        {
                            // Create the ground floor
                            placeholder = new GroundFloor();
                            placeholder->Position(x + depth, height, z + width);
                            house->push_back(placeholder);
                        }
                        else if (height < 12)
                        {
                            // Create the first floor
                            placeholder = new OtherFloor();
                            placeholder->Position(x + depth, height, z + width);
                            house->push_back(placeholder);
                        }
                        else if (height < 16) {
                            // Make sure it doesn't clip through the roof
                            if (depth >= -2) {
                                // Create the second floor
                                placeholder = new OtherFloor();
                                placeholder->Position(x + depth, height, z + width);
                                house->push_back(placeholder);
                            }
                        }
                    }
                }
                else {
                    if (height < 6)
                    {
                        // Create the ground floor
                        placeholder = new GroundFloor();
                        placeholder->Position(x + depth, height, z + width);
                        house->push_back(placeholder);
                    }
                    else if (height < 12)
                    {
                        // Create the first floor
                        placeholder = new OtherFloor();
                        placeholder->Position(x + depth, height, z + width);
                        house->push_back(placeholder);
                    }
                    else if (height < 16) {
                        // At the back the wall is entirely filled
                        if (depth > 0 || (width >= quarterWidth && width < (widthMax - quarterWidth) - 1)) {
                            // Create the second floor
                            placeholder = new OtherFloor();
                            placeholder->Position(x + depth, height, z + width);
                            house->push_back(placeholder);

                            // At the front of the house there is another square needed
                            if (depth < 0) {
                                placeholder = new OtherFloor();
                                placeholder->Position(x + (depth + 2), height, z + width);
                                house->push_back(placeholder);
                            }

                            // Create the roof
                            // But only at the correct height
                            if (height > 13) {
                                int tempMin = (depth < 0 ? depth : -2);
                                int tempMax = (depth < 0 ? 0 : 7);
                                for (int i = tempMin; i < tempMax; i++) {
                                    placeholder = new Roof();
                                    placeholder->Position(x + i, height + 1.001, z + width);
                                    house->push_back(placeholder);
                                }

                            }
                        }
                        else {
                            // Create the angled roof
                            placeholder = new Roof();
                            if (height > 13) placeholder->Position(x + (depth + 2), height, z + width);
                            else placeholder->Position(x + depth, height, z + width);
                            placeholder->Rotate(0, 0, 45);
                            placeholder->Scale(1.42, 1, 1);
                            house->push_back(placeholder);
                        }
                    }

                }
            }
        }
    }
    return house;
}

std::vector<Object*>* ObjectManager::CreateLamp(float x, float z)
{
    vector<Object*>* lamp = new vector<Object*>();

    Object* lamp_post = new Lamppost();
    lamp_post->Scale(1, 1.5, 1);
    lamp_post->Position(x, 2.25f, z);
    lamp->push_back(lamp_post);

    Object* lamp_light = new Lamplight();
    lamp_light->Scale(0.45);
    lamp_light->Rotate(180, 0, 0);
    lamp_light->Position(x, 4.8f, z);
    lamp->push_back(lamp_light);

    return lamp;
}

std::vector<Object*>* ObjectManager::CreateOther()
{
    vector<Object*>* other = new vector<Object*>();

    Object* spinning_can = new Can();
    spinning_can->Scale(0.95);
    spinning_can->Position(26, 0.1f, 30);
    other->push_back(spinning_can);

    return other;
}

