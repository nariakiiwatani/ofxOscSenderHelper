#include "ofxOscSenderHelper.h"
#include "ofxOscSender.h"

void ofxOscSenderHelper::send(const string &address, int value)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	msg.addIntArg(value);
	sender_.sendMessage(msg);
}

void ofxOscSenderHelper::send(const string &address, float value)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	msg.addFloatArg(value);
	sender_.sendMessage(msg);
}

void ofxOscSenderHelper::send(const string &address, long value)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	msg.addInt64Arg(value);
	sender_.sendMessage(msg);
}

void ofxOscSenderHelper::send(const string &address, string value)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	msg.addStringArg(value);
	sender_.sendMessage(msg);
}


void ofxOscSenderHelper::send(const string &address, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	ofxOscMessage msg;
	msg.setAddress(address);
	while(*fmt) {
		switch(*fmt++) {
		case 'i': msg.addIntArg(va_arg(ap, int));		break;
		case 'f': msg.addFloatArg(va_arg(ap, double));	break;
		case 'l': msg.addInt64Arg(va_arg(ap, long));	break;
		case 's': msg.addStringArg(va_arg(ap, char*));	break;
		}
	}
	sender_.sendMessage(msg);
	va_end(ap);
}

void ofxOscSenderHelper::send(const string &address, const int *arg, size_t num)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	while(num--) {
		msg.addIntArg(*arg++);
	}
	sender_.sendMessage(msg);
}
void ofxOscSenderHelper::send(const string &address, const vector<int> &arg)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	vector<int>::const_iterator it = arg.begin();
	vector<int>::const_iterator end = arg.end();
	while(it != end) {
		msg.addIntArg(*it++);
	}
	sender_.sendMessage(msg);
}

void ofxOscSenderHelper::send(const string &address, const float *arg, size_t num)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	while(num--) {
		msg.addFloatArg(*arg++);
	}
	sender_.sendMessage(msg);
}
void ofxOscSenderHelper::send(const string &address, const vector<float> &arg)
{
	ofxOscMessage msg;
	msg.setAddress(address);
	vector<float>::const_iterator it = arg.begin();
	vector<float>::const_iterator end = arg.end();
	while(it != end) {
		msg.addFloatArg(*it++);
	}
	sender_.sendMessage(msg);
}

/* EOF */
