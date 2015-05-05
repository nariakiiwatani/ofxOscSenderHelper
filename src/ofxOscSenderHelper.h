/*!
 */

#pragma once

#include "ofTypes.h"

#define OFX_OSC_SENDER_HELPER_NAMESPACE_BEGIN namespace ofx{namespace osc{
#define OFX_OSC_SENDER_HELPER_NAMESPACE_END }}

class ofxOscSender;

OFX_OSC_SENDER_HELPER_NAMESPACE_BEGIN

class SenderHelper
{
public:
	SenderHelper(ofxOscSender &sender):sender_(sender){}
	// only 1 argument
	void send(const string &address, int value);
	void send(const string &address, float value);
	void send(const string &address, long value);
	void send(const string &address, string value);
	// vector
	void send(const string &address, const vector<int> &arg);
	void send(const string &address, const vector<float> &arg);
	void send(const string &address, const vector<string> &arg);
	// array
	void send(const string &address, const int *arg, size_t num);
	void send(const string &address, const float *arg, size_t num);
	
	// various arguments
	// fmt : you can use these
	// i: int
	// f: float
	// l: long
	// s: string (c_str style)
	void send(const string &address, const char *fmt, ...);

private:
	ofxOscSender &sender_;
};

OFX_OSC_SENDER_HELPER_NAMESPACE_END

typedef ofx::osc::SenderHelper ofxOscSenderHelper;

/* EOF */
