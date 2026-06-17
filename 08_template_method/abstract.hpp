#pragma once

class AWaitTemplateClass
{
public:
    AWaitTemplateClass  ();
    virtual ~AWaitTemplateClass ();    

void run();

private:
    virtual void wait           () = 0;
    virtual void do_something   () = 0;
    virtual bool exit           () = 0;
    
    //hook
    virtual void close();
};