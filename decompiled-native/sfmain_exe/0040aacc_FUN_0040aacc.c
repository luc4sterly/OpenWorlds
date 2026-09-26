// 0040aacc FUN_0040aacc [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0040aacc(undefined4 param_1,undefined1 *param_2)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  undefined4 extraout_ECX;
  int iVar3;
  int extraout_EDX;
  int unaff_EBX;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  
  local_1c = unaff_EBX / 7;
  local_18 = 0;
  for (iVar5 = 0; iVar5 < local_1c; iVar5 = iVar5 + 1) {
    DAT_00445288 = 0;
    iVar3 = 0;
    do {
      iVar2 = DAT_00445288 >> 3;
      bVar1 = (byte)DAT_00445288;
      iVar4 = DAT_00445288 + 1;
      DAT_00445288 = iVar4;
      *(uint *)((int)&DAT_00444d58 + iVar3) =
           (uint)(((uint)*(byte *)(iVar2 + in_EAX) & 1 << (bVar1 & 7)) != 0);
      iVar3 = iVar3 + 4;
    } while (iVar4 < 0x140);
    FUN_0040c8c2(0x445254,&DAT_00445284,(uint *)&DAT_00444d54);
    FUN_0040c058(0x445288,(int *)&DAT_00445280,(int *)&DAT_004452c0,(float *)&DAT_004452bc,
                 (float *)&DAT_00445290);
    FUN_0040975c((undefined4 *)&DAT_00445290,(int *)&DAT_004452c0,0x444814,&local_20);
    in_EAX = in_EAX + 7;
    FUN_0040a8a0(extraout_ECX,&DAT_00444818);
    do {
      fVar6 = FUN_0042b8ce();
      local_14 = (uint)ROUND(fVar6);
      *param_2 = (&DAT_00427192)[(int)(local_14 & 0xffff) >> 3];
      param_2 = param_2 + 1;
    } while (extraout_EDX != 0x2cc);
    local_18 = local_18 + 0xb4;
  }
  return local_18;
}


