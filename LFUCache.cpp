//
// Created by Levi Duran on 11/26/16.
//
#include <iostream>
#include <list>
class LFUCache {




public:


    class Cache{


    protected:

        class MyMap{
            int key;
            int value;
            long timestamp;

            public:MyMap(int key,int value){
                    this->key = key;
                    this->value = value;
                }
            public:MyMap(){}

            int getKey(){
                return this->key;
            }

            int getValue(){
                return this->value;
            }
            void setKey(int key){
                this->key = key;
            }

            void setValue(int value){
                this->value = value;
            }
        };


    public:


        std::list <MyMap*> entries ; //size zero
        //std::list <MyMap> entries ; //size zero

        Cache(int capacity){
            //entries.resize(capacity);

        }


        int get(int key){
            //validate non positive key


            //std::cout << "entries size : " << entries.size() << std::endl;


            //iterate MYMAP entries
            std::list<MyMap*>::iterator it;
            //std::list<MyMap>::iterator it;

            for (it = entries.begin(); it != entries.end(); ++it){

                //std::cout << "inside loop" << std::endl;


                //std::cout << "key: " << (*it)->getKey() << std::endl;
                ///std::cout << "value: " << (*it)->getValue() << std::endl;

                if((*it)->getKey() == key){
                    //std::cout << "returning value: " << (*it)->getValue() << std::endl;
                    return ((*it)->getValue());
                }
                else{
                    continue;
                }
            }

            return -1;
        }


        void set(int key,int value){
            //validate before creating new element
            //capacity invalidate least frequently used entry
            //existing key


            //std::cout << "creating new entry" << std::endl;

            MyMap* element = new MyMap(key,value);
            //MyMap element (key,value);

            //element.setKey(key);
            //element.setValue(value);

            element->setKey(key);
            element->setValue(value);

            entries.push_front(element);



        }


    };

    Cache *cache =  NULL;
    LFUCache(int capacity) {
        cache = new Cache(capacity);
    }



    int get(int key) {
        //std::cout << "get key in cache : " << cache->get(key) << std::endl;
        return cache->get(key);
    }

    void set(int key, int value) {
        cache->set(key,value);
    }

    public:LFUCache(){}


};


int main() {

    LFUCache obj(2);
    obj.set(1,9);
    obj.set(2,10);
    obj.set(3,13);
    obj.set(4,22);
    obj.set(5,9);
    obj.set(6,101);
    obj.set(7,1311);
    obj.set(7,2203);
    std::cout << obj.get(8) << std::endl;
    return 0;
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */