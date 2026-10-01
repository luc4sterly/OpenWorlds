// 004177c0 FUN_004177c0 [Global]
// program: sfmain.exe

MMRESULT __fastcall FUN_004177c0(DWORD_PTR param_1,UINT param_2,DWORD_PTR param_3,DWORD param_4)

{
  LPHWAVEOUT in_EAX;
  LPCWAVEFORMATEX unaff_EBX;
  MMRESULT local_10;
  
  if ((DAT_0043d5cc == 0) || (unaff_EBX->nSamplesPerSec != 8000)) {
    if ((DAT_0043d5d0 == 0) || (unaff_EBX->wBitsPerSample != 0x10)) {
      local_10 = waveOutOpen(in_EAX,param_2,unaff_EBX,param_1,param_3,param_4);
      if ((param_4 != 1) && (local_10 == 0)) {
        FUN_004296b9(s_waveOutOpen___0043619a);
      }
    }
    else {
      local_10 = 0x20;
    }
  }
  else {
    local_10 = 0x20;
  }
  return local_10;
}


