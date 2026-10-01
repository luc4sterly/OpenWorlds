// 004174b5 FUN_004174b5 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004174b5(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  code *pcVar2;
  LONG LVar3;
  HWND local_1c;
  
  if (DAT_004627c8 != (HWND)0x0) {
    uVar1 = SendMessageA(DAT_004627c8,0x229,0,0);
    local_1c = (HWND)(uVar1 & 0xffff);
    if (((local_1c != (HWND)0x0) &&
        (pcVar2 = (code *)GetWindowLongA(local_1c,-4), pcVar2 == FUN_004110e1)) &&
       (LVar3 = GetWindowLongA(local_1c,0), LVar3 != 0)) goto LAB_0041752e;
  }
  local_1c = (HWND)0x0;
LAB_0041752e:
  return CONCAT44(param_2,local_1c);
}


