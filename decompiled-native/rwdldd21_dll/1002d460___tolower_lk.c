// 1002d460 __tolower_lk [Global]
// program: RWDLDD21.DLL

/* Library Function - Single Match
    __tolower_lk
   
   Library: Visual Studio 1998 Release */

uint __cdecl __tolower_lk(uint param_1)

{
  uint uVar1;
  LPCSTR _LpSrcStr;
  int iVar2;
  int unaff_EBX;
  uint in_stack_fffffff8;
  byte local_4;
  byte local_3;
  undefined1 local_2;
  
  if (DAT_10037890 == (_locale_t)0x0) {
    if ((0x40 < (int)param_1) && ((int)param_1 < 0x5b)) {
      param_1 = param_1 + 0x20;
    }
    return param_1;
  }
  if ((int)param_1 < 0x100) {
    if (DAT_10036ee0 < 2) {
      uVar1 = *(ushort *)(PTR_DAT_10036b40 + param_1 * 2) & 1;
    }
    else {
      uVar1 = __isctype(param_1,1);
    }
    if (uVar1 == 0) {
      return param_1;
    }
  }
  local_4 = (byte)(param_1 >> 8);
  if ((PTR_DAT_10036b40[(uint)local_4 * 2 + 1] & 0x80) == 0) {
    _LpSrcStr = (LPCSTR)0x1;
    local_3 = 0;
    local_4 = (byte)param_1;
  }
  else {
    _LpSrcStr = (LPCSTR)0x2;
    local_2 = 0;
    local_3 = (byte)param_1;
  }
  iVar2 = ___crtLCMapStringA(DAT_10037890,(LPCWSTR)0x100,(DWORD)&local_4,_LpSrcStr,
                             (int)&stack0xfffffff8,(LPSTR)0x3,0,unaff_EBX,in_stack_fffffff8);
  if (iVar2 == 0) {
    return param_1;
  }
  if (iVar2 == 1) {
    return in_stack_fffffff8 & 0xff;
  }
  return in_stack_fffffff8 & 0xffff;
}


