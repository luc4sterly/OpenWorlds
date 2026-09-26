// 00402753 FUN_00402753 [Global]
// programa: gdkup.exe

int __fastcall FUN_00402753(undefined4 param_1,byte *param_2)

{
  byte *in_EAX;
  int iVar1;
  int unaff_EBX;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  iVar1 = 0;
  bVar3 = true;
  do {
    if (unaff_EBX == 0) break;
    unaff_EBX = unaff_EBX + -1;
    bVar2 = *in_EAX < *param_2;
    bVar3 = *in_EAX == *param_2;
    in_EAX = in_EAX + 1;
    param_2 = param_2 + 1;
  } while (bVar3);
  if (!bVar3) {
    iVar1 = (1 - (uint)bVar2) - (uint)(bVar2 != 0);
  }
  return iVar1;
}


