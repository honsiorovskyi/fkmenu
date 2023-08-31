/*
Copyright (c) 2022 fkmenu developers

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Carbon/Carbon.h>
#include "mouse.h"

CGEventRef eventTapCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon)
{
	switch (type)
	{
	case kCGEventMouseMoved:
		return handleMouseMoved(proxy, type, event, refcon);
	}

	return event;
}

void setupCGEventTap()
{
	// CGEventMask eventMask = kCGEventMaskForAllEvents;
	CGEventMask eventMask = (CGEventMaskBit(kCGEventMouseMoved));

	CFMachPortRef eventTap = CGEventTapCreate(
		kCGHIDEventTap,
		kCGHeadInsertEventTap,
		kCGEventTapOptionDefault,
		eventMask,
		&eventTapCallback,
		NULL);

	if (!eventTap)
	{
		fprintf(stderr, "failed to create event tap\n");
		exit(1);
	}

	CFRunLoopSourceRef runLoopSourceRef = CFMachPortCreateRunLoopSource(NULL, eventTap, 0);
	CFRelease(eventTap);

	CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSourceRef, kCFRunLoopDefaultMode);
	CFRelease(runLoopSourceRef);

	CGEventTapEnable(eventTap, true);
}

int main(void)
{
	setupCGEventTap();

	CFRunLoopRun();
}
