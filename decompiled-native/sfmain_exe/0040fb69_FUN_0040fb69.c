// 0040fb69 FUN_0040fb69 [Global]
// programa: sfmain.exe

void __fastcall FUN_0040fb69(undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int local_20;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  for (local_20 = 0; local_20 < iVar1; local_20 = local_20 + 1) {
    *(undefined2 *)(&DAT_00451ab1 + local_20 * 2) =
         *(undefined2 *)(&DAT_00426f92 + (uint)*(byte *)(in_EAX + local_20 + 0x1c) * 2);
  }
  FUN_0042b721(param_1);
  iVar1 = iVar1 / 3;
  for (local_20 = 0; local_20 < iVar1; local_20 = local_20 + 1) {
    *(undefined1 *)(in_EAX + local_20 + 0x1c) =
         (&DAT_00427192)[(int)(uint)*(ushort *)(&DAT_00451ab1 + local_20 * 6) >> 3];
  }
  *(int *)(in_EAX + 0x14) = iVar1;
  return;
}


