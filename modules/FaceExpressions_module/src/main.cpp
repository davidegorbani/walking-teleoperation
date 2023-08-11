// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#include <FaceExpressionsRetargeting.hpp>
#include <yarp/os/Network.h>
#include <yarp/os/LogStream.h>

int main(int argc, char* argv[])
{

    yarp::os::Network yarp;
    if (!yarp.checkNetwork())
    {
        yError()<<"[main] Unable to find YARP network";
        return EXIT_FAILURE;
    }

    // prepare and configure the resource finder
    yarp::os::ResourceFinder& rf = yarp::os::ResourceFinder::getResourceFinderSingleton();

    rf.setDefaultConfigFile("faceExpressionsConfig.ini");

    rf.configure(argc, argv);

    FaceExpressionsRetargetingModule speechmodule;

    return speechmodule.runModule(rf);
}
