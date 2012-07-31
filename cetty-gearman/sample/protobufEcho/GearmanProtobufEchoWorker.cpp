#include <cstdio>
#include <cetty/config/ConfigCenter.h>
#include <cetty/gearman/protobuf/builder/GearmanProtobufWorkerBuilder.h>
#include "echo.pb.h"


using namespace cetty::config;
using namespace cetty::gearman::protobuf::builder;

namespace echo {

class EchoServiceImpl : public EchoService {
public:
    EchoServiceImpl() {}
    virtual ~EchoServiceImpl() {
    }

    virtual void Echo(const ConstEchoRequestPtr& request,
                      const EchoResponsePtr& response,
                      const DoneCallback& done) {
        EchoResponsePtr rep(response);

        if (!response) {
            rep = new EchoResponse;
        }

        rep->set_payload(request->payload());

        //to call the callback
        if (done) {
            done(static_pointer_cast<google::protobuf::Message>(rep));
        }
    }
};

}

int main(int argc, char* argv[]) {
    //ConfigCenter::instance().load(argc, argv);

    GearmanProtobufWorkerBuilder builder(1);
    builder.registerService(new echo::EchoServiceImpl);
    builder.addConnection("192.168.1.162",4730);
    builder.buildWorkers();

    getchar();
    //builder.buildAll();
    //builder.waitingForExit();

    return 0;
}
