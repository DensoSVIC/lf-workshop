# Lingua Franca Workshop
The objective of this workshop is to get familiar with basic features of Lingua Franca. We will ll go a step further to discuss how it can be applied for the development of time critical software applications. 

We recommend visiting the [Lingua Franca](https://www.lf-lang.org/) project page for more details.



## Development Environment

We have created two development environments for you to try the workshop examples. [Gitpod](http://gitpod.io) and [Codespaces](https://github.com/codespaces/) allow you to launch the containerized environment and support editing in [VS Code](https://code.visualstudio.com/) (Browser based or Desktop version).

**You are responsible for the costs incurred for working on both these environments. Kindly review the pricing and make sure you maximize your free credits as an individual user.**

 - [GitHub Codespaces Pricing](https://docs.github.com/en/billing/managing-billing-for-github-codespaces/about-billing-for-github-codespaces)
 - [Gitpod Pricing](https://www.gitpod.io/pricing)

If you are not comfortable with the above environments, please follow the links below to build the development environment on your compute machine.
 - [Download and build](https://www.lf-lang.org/download)
 - [Install RTI for C](https://www.lf-lang.org/docs/handbook/distributed-execution?target=c#installation-of-the-rti)



## Launching your development environment
[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://github.com/codespaces/new?hide_repo_select=true&ref=main&repo=598781284&devcontainer_path=.devcontainer%2Fdevcontainer.json&location=WestUs2)

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/DensoSVIC/lf-workshop.git)

<!--- 
### Launch containerized version
[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://github.com/codespaces/new?hide_repo_select=true&ref=main&repo=598781284&devcontainer_path=.devcontainer%2Fcontainerized%2Fdevcontainer.json&location=WestUs2)
-->
Your environment can take up to a few minutes to build the container image and load the editor. Once you pass this step, you are ready for the LF programming experience!

## Getting started with the examples
Make sure you have the compiler built in the previous step by bringing up the terminal in the editor and typing in `lfc`. By default, the terminal points to 'lf-workshop' directory. To run an example, use the command `lfc src/<example>.lf` to build and run the generated binary `bin/example`.
Example: lfc src/HelloWorld.lf


You can also use the features of the in-built editor by pressing `ctrl+shift+p` and selecting `Lingua Franca: Build and Run` option which builds and runs the program for you. To render the diagram view of your Lingua Franca code, click the ![diagram-image](icons/diagram-icon.png "Keiler Diagram") icon on the top right corner of the editor window in which the `.lf` program is opened.

## Before you leave
When you are done with the workshop, cleanup your unused/stopped instances you may have created during the event to avoid being billed.
* [on Github](https://github.com/codespaces/)
* [On Gitpod](https://gitpod.io/workspaces)


## Acknowledgements
We extend our sincere thanks to [Prof. Edward Lee](https://www2.eecs.berkeley.edu/Faculty/Homepages/lee.html) and to the amazing [Lingua Franca community](https://www.lf-lang.org/community). The scripts used for containerized development environments have been borrowed with permission from [Lingua Franca playground repository](https://github.com/lf-lang/lingua-franca-playground). 