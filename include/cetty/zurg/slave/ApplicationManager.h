/*
 * ApplicationManager.h
 *
 *  Created on: 2012-11-1
 *      Author: chenhl
 */

#ifndef APPLICATIONMANAGER_H_
#define APPLICATIONMANAGER_H_

#include <map>
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include <cetty/channel/EventLoop.h>
#include <cetty/zurg/slave/Process.h>
#include <cetty/zurg/slave/slave.pb.h>
#include <cetty/zurg/slave/slave_service.pb.h>

struct rusage;

namespace cetty {
namespace zurg {
namespace slave {

class Process;
class ProcessManager;

using namespace cetty::channel;

class ApplicationManager : boost::noncopyable {
private:
    struct Application {
        AddApplicationRequest request;
        ApplicationStatus status;
    };
    typedef std::map<std::string, Application> Applications;

public:
    ApplicationManager(ProcessManager&);
    ~ApplicationManager();

    void add(const ConstAddApplicationRequestPtr& request,
             const AddApplicationResponsePtr& response,
             const DoneCallback& done);

    void start(const ConstStartApplicationsRequestPtr& request,
               const StartApplicationsResponsePtr& response,
               const DoneCallback& done);

    void stop(const ConstStopApplicationRequestPtr& request,
              const StopApplicationResponsePtr& response,
              const DoneCallback& done);

    void list(const ConstListApplicationsRequestPtr& request,
              const ListApplicationsResponsePtr& response,
              const DoneCallback& done);

    void remove(const ConstRemoveApplicationsRequestPtr& request,
                const RemoveApplicationsResponsePtr& response,
                const DoneCallback& done);

    // kill all applications started by #startApp() and self
    void stopAll();

private:
    void startApp(const Application&, ApplicationStatus* out);
    void onProcessExit(const ProcessPtr&,
                       int status,
                       const struct rusage&);

private:
    Applications applications_;
    ProcessManager& processManager_;
};

}
}
}

#endif /* APPLICATIONMANAGER_H_ */
