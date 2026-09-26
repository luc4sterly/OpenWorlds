// 004079c3 FUN_004079c3 [Global]
// programa: run.exe

uint __cdecl FUN_004079c3(WCHAR param_1,ushort param_2)

{
  BOOL BVar1;
  uint local_8;
  
  if (param_1 == L'\xffff') {
    return 0;
  }
  if ((ushort)param_1 < 0x100) {
    local_8 = (uint)*(ushort *)(PTR_DAT_0040b5b4 + (uint)(ushort)param_1 * 2);
  }
  else {
    BVar1 = FUN_00407a15(1,&param_1,1,(LPWORD)&local_8,0,0);
    if (BVar1 == 0) {
      return 0;
    }
  }
  return local_8 & 0xffff & (uint)param_2;
}


