#include <windows.h>
#include <stdio.h>

int main()
{
	constexpr unsigned int kMaxTitleLength = 256;
	constexpr unsigned int kSleepInterval_ms = 1000;
	char sTitle[kMaxTitleLength] = { 0 };
	while (true)
	{
		HWND w = GetForegroundWindow();
		int err = GetWindowTextA(w, sTitle, kMaxTitleLength);
		if (err != 0)
		{
			printf(sTitle);
			printf("\n");
		}
		else
		{
			printf("! Internal error: %d\n", GetLastError());
		}
		Sleep(kSleepInterval_ms);
	}
	return 0;
}
