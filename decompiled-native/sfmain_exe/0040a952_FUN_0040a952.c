// 0040a952 FUN_0040a952 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall FUN_0040a952(undefined4 param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  byte *in_EAX;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  byte *pbVar4;
  int iVar5;
  int unaff_EBX;
  int iVar6;
  int local_14;
  
  bVar1 = DAT_00427192;
  local_14 = 0;
  if (unaff_EBX % 0xb4 != 0) {
    iVar6 = 0xb4 - unaff_EBX % 0xb4;
    while (0 < iVar6) {
      in_EAX[unaff_EBX] = bVar1;
      iVar6 = iVar6 + -1;
      unaff_EBX = unaff_EBX + 1;
    }
  }
  for (iVar6 = 0; iVar6 < unaff_EBX / 0xb4; iVar6 = iVar6 + 1) {
    fVar2 = (float)_DAT_00435868;
    iVar5 = 0;
    pbVar4 = in_EAX;
    do {
      bVar1 = *pbVar4;
      iVar3 = iVar5 + 4;
      pbVar4 = pbVar4 + 1;
      *(float *)((int)&DAT_00443d6c + iVar5) =
           (float)*(short *)(&DAT_00426f92 + (uint)bVar1 * 2) * fVar2;
      iVar5 = iVar3;
    } while (iVar3 != 0x2d0);
    FUN_0040b2d4();
    FUN_0040d14e(extraout_ECX,(undefined4 *)&DAT_004447e0,0x4447e4);
    FUN_00408098(extraout_ECX_00,0);
    FUN_00408098(extraout_ECX_01,0);
    FUN_0040b641((int *)&DAT_004447d8,(uint *)&DAT_004447d4,(int *)&DAT_004447a8);
    FUN_0040c8c2(0x4447a8,(undefined4 *)&DAT_004447d8,(uint *)&DAT_004442a8);
    iVar5 = 0;
    DAT_004447dc = 0;
    do {
      pbVar4 = (byte *)(param_2 + (DAT_004447dc >> 3));
      *pbVar4 = *pbVar4 | (*(int *)((int)&DAT_004442ac + iVar5) != 0) << ((byte)DAT_004447dc & 7);
      DAT_004447dc = DAT_004447dc + 1;
      iVar5 = iVar5 + 4;
    } while (DAT_004447dc < 0x140);
    param_2 = param_2 + 7;
    in_EAX = in_EAX + 0xb4;
    local_14 = local_14 + 7;
  }
  return local_14;
}


