// 00402fc1 FUN_00402fc1 [Global]
// programa: sfmain.exe

void __fastcall FUN_00402fc1(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined2 *in_EAX;
  int iVar2;
  
  iVar2 = 1;
  do {
    iVar2 = iVar2 + 1;
    uVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  } while (iVar2 < 9);
  return;
}


