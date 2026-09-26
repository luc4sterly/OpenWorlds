// 004064ae FUN_004064ae [Global]
// programa: run.exe

int __cdecl
FUN_004064ae(LCID param_1,DWORD param_2,PCNZWCH param_3,int param_4,LPCWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004084d0;
  puStack_10 = &LAB_00403400;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_0040bbb8 == 0) {
    ExceptionList = &local_14;
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringA(0,0,"",1,"",1);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_0040bbb8 = 2;
    }
    else {
      DAT_0040bbb8 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_00407993(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_00407993(param_5,param_6);
  }
  if ((param_4 != 0) && (param_6 != 0)) {
    if (DAT_0040bbb8 == 1) {
      iVar1 = CompareStringW(param_1,param_2,param_3,param_4,param_5,param_6);
      ExceptionList = local_14;
      return iVar1;
    }
    if (DAT_0040bbb8 == 2) {
      if (param_7 == 0) {
        param_7 = DAT_0040bbd4;
      }
      iVar1 = WideCharToMultiByte(param_7,0x220,param_3,param_4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0
                                 );
      if (iVar1 != 0) {
        local_8 = 0;
        FUN_004062f0();
        local_8 = 0xffffffff;
        if ((&stack0x00000000 != (undefined1 *)0x38) &&
           (iVar2 = WideCharToMultiByte(param_7,0x220,param_3,param_4,&stack0xffffffc8,iVar1,
                                        (LPCSTR)0x0,(LPBOOL)0x0), iVar2 != 0)) {
          iVar2 = WideCharToMultiByte(param_7,0x220,param_5,param_6,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
          if (iVar2 != 0) {
            local_8 = 1;
            FUN_004062f0();
            local_8 = 0xffffffff;
            if ((&stack0x00000000 != (undefined1 *)0x38) &&
               (iVar3 = WideCharToMultiByte(param_7,0x220,param_5,param_6,&stack0xffffffc8,iVar2,
                                            (LPCSTR)0x0,(LPBOOL)0x0), iVar3 != 0)) {
              iVar1 = CompareStringA(param_1,param_2,&stack0xffffffc8,iVar1,&stack0xffffffc8,iVar2);
              ExceptionList = local_14;
              return iVar1;
            }
          }
        }
      }
    }
    ExceptionList = local_14;
    return 0;
  }
  if (param_4 != param_6) {
    ExceptionList = local_14;
    return ((-1 < param_4 - param_6) - 1 & 0xfffffffe) + 3;
  }
  ExceptionList = local_14;
  return 2;
}


