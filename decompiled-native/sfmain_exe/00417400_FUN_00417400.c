// 00417400 FUN_00417400 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00417400(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int in_EAX;
  code *pcVar2;
  LONG LVar3;
  HWND local_20;
  HWND local_1c;
  
  local_20 = GetWindow(DAT_004627c8,5);
  do {
    if (local_20 == (HWND)0x0) {
      local_1c = (HWND)0x0;
LAB_004174a9:
      return CONCAT44(param_2,local_1c);
    }
    pcVar2 = (code *)GetWindowLongA(local_20,-4);
    if ((((pcVar2 == FUN_004110e1) && (LVar3 = GetWindowLongA(local_20,0), LVar3 != 0)) &&
        (*(int *)(LVar3 + 0x18) == *(int *)(in_EAX + 4))) &&
       (sVar1 = Ordinal_15(*(undefined2 *)(in_EAX + 2)), sVar1 == *(short *)(LVar3 + 0x24))) {
      local_1c = local_20;
      goto LAB_004174a9;
    }
    local_20 = GetWindow(local_20,2);
  } while( true );
}


