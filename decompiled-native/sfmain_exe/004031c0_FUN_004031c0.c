// 004031c0 FUN_004031c0 [Global]
// programa: sfmain.exe

void __fastcall FUN_004031c0(ushort *param_1,int param_2,short *param_3)

{
  short sVar1;
  int in_EAX;
  short *psVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  short sVar6;
  int unaff_EBX;
  uint uVar7;
  short sVar8;
  ushort *local_1c;
  
  local_1c = param_1;
  while (unaff_EBX = unaff_EBX + -1, unaff_EBX != -1) {
    uVar7 = (uint)*local_1c;
    psVar4 = (short *)(param_2 + 0x10);
    psVar2 = (short *)(in_EAX + 0x280);
    while( true ) {
      psVar3 = psVar2 + -1;
      psVar4 = psVar4 + -1;
      sVar6 = (short)uVar7;
      if (psVar3 == (short *)(in_EAX + 0x26e)) break;
      sVar1 = *psVar4;
      if ((sVar1 == -0x8000) && (*psVar3 == -0x8000)) {
        sVar8 = 0x7fff;
      }
      else {
        sVar8 = (short)((int)*psVar3 * (int)sVar1 + 0x4000 >> 0xf);
      }
      uVar7 = (int)sVar6 - (int)sVar8;
      if ((int)uVar7 < 0x7fff) {
        if ((int)uVar7 < -0x7fff) {
          uVar7 = 0xffff8000;
        }
      }
      else {
        uVar7 = 0x7fff;
      }
      if ((sVar1 == -0x8000) && ((short)uVar7 == -0x8000)) {
        sVar6 = 0x7fff;
      }
      else {
        sVar6 = (short)((int)(short)uVar7 * (int)sVar1 + 0x4000 >> 0xf);
      }
      iVar5 = (int)sVar6 + (int)*psVar3;
      if (0xffff < iVar5 + 0x8000U) {
        if (iVar5 < 1) {
          iVar5 = -0x8000;
        }
        else {
          iVar5 = 0x7fff;
        }
      }
      *psVar2 = (short)iVar5;
      psVar2 = psVar3;
    }
    *(short *)(in_EAX + 0x270) = sVar6;
    *param_3 = sVar6;
    param_3 = param_3 + 1;
    local_1c = local_1c + 1;
  }
  return;
}


