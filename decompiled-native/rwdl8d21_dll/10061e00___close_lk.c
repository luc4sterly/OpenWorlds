// 10061e00 __close_lk [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __close_lk
   
   Library: Visual Studio 1998 Release */

undefined4 __cdecl __close_lk(uint param_1)

{
  intptr_t iVar1;
  intptr_t iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  
  if ((param_1 == 1) || (param_1 == 2)) {
    iVar1 = __get_osfhandle(2);
    iVar2 = __get_osfhandle(1);
    if (iVar1 != iVar2) goto LAB_10061e2a;
  }
  else {
LAB_10061e2a:
    hObject = (HANDLE)__get_osfhandle(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_10061e4a;
    }
  }
  DVar4 = 0;
LAB_10061e4a:
  __free_osfhnd(param_1);
  if (DVar4 != 0) {
    __dosmaperr(DVar4);
    return 0xffffffff;
  }
  *(undefined1 *)
   (*(int *)((int)&DAT_10079310 + ((int)(param_1 & 0xffffffe7) >> 3)) + 4 + (param_1 & 0x1f) * 0x24)
       = 0;
  return 0;
}


