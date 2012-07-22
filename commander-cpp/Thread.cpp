#include "Thread.h"
#include <pthread.h>
#include <iostream>
#include <cstdlib>
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
using namespace std;
using namespace tpool;

void* Thread::thread_func(void* thisObj)
{
    Thread* obj = static_cast<Thread*>(thisObj);
    obj->Entry();
    return NULL;
}

Thread::ThreadId Thread::Run()
{
    //_open = true;
    if (pthread_create(&(m_threadId.id), NULL,
                       thread_func, (void*) this) != 0)
    {
        cerr << "pthread_create failed" << endl;
        exit(1);
    }
    
    m_threadId.isValid = true;
    return m_threadId;
}

void Thread::Stop()
{
    if (!m_threadId.isValid)
    {
        return;
    }
    
    pthread_cancel(m_threadId.id);
}

Thread::ThreadId Thread::GetId() const
{
    return m_threadId;
}