// 00430e90 FUN_00430e90 [Global]
// programa: sfmain.exe

void __fastcall FUN_00430e90(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int in_EAX;
  byte *extraout_ECX;
  byte *pbVar2;
  
  FUN_00408098(param_2,0);
  for (pbVar2 = extraout_ECX; bVar1 = *pbVar2, bVar1 != 0; pbVar2 = pbVar2 + 1) {
    *(byte *)(in_EAX + ((int)(uint)bVar1 >> 3)) =
         *(byte *)(in_EAX + ((int)(uint)bVar1 >> 3)) | (&DAT_00437d18)[bVar1 & 7];
  }
  return;
}


