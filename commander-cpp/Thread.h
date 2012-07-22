///////////////////////////////////////////////////////////////
//Welcome to the undocumented Thread class! Don't even bother//
//to try to figure out what this actually does, because it is//
//a waste of time. I will  never comment or do anything  with//
//the way this file is. It probably wont ever change.  If you//
//wish to  see what  it actually  does  please  check  out my//
//and look for  the Tpool  repository, I  may or may not have//
//added comments there to describe it all. This class is free//
//software, you may  use it in any way that you wish, as long//
//as this original text is left on this document. If you wish//
//to see  the changelog, please look on github. If you cannot//
//for some reason find it on github please consult google.com//
//this software is distributed in  the hope that it is useful//
//and is accompanied with no warranty whatsoever. It is up to//
//the programmer to ensure the saftey of the code written and//
//that if  they choose to supply a  warranty it is sufficient//
//original code by Ethan Laur (phyrrus9) <phyrrus9@gmail.com>//
///////////////////////////////////////////////////////////////
#ifndef _TPOOL_THREAD_H_
#define _TPOOL_THREAD_H_

#include <pthread.h>

namespace tpool {
    
    class Thread {
    private:
        static void* thread_func(void* thisObj);
        
        struct Tid {
            bool isValid;
            pthread_t id;
            
            Tid() : isValid(false)
            {
            }
        };
        
    public:
        typedef Tid ThreadId;
        
        virtual ~Thread() {}
        
        ThreadId Run();
        void Stop();
        ThreadId GetId() const;
        //bool _open; //don't use this please
        //bool isrunning() const; //returns true if task is running
    protected:
        virtual void Entry() = 0;
        
    private:
        ThreadId m_threadId;
    };
    
}

#endif