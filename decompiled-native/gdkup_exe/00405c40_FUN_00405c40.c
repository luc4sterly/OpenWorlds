// 00405c40 FUN_00405c40 [Global]
// programa: gdkup.exe

void __fastcall FUN_00405c40(undefined4 param_1)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x1c) = 3;
  }
  *(byte *)(in_EAX + 4) = *(byte *)(in_EAX + 4) | 1;
  thunk_FUN_004070b8(param_1,iVar1);
  return;
}


