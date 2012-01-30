#include "socialnode.hpp"
#include <sstream>

SocialNode::SocialNode(int id_) :
       Node(id_)
{
}

void SocialNode::addFriend(Edge * friend_){

    friends.push_back(friend_);

}

std::string SocialNode::toXML(){

    std::stringstream ss;
    ss << "<node id =  "<< nodeID << "/>";
    return ss.str();

}

std::vector<Edge*>* SocialNode::getFriends(){

    return &friends;

}
