// 00412340 FUN_00412340 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00412340(int param_1)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte local_18 [4];
  byte *local_14;
  
  do {
    local_14 = local_18;
    bVar4 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))
                      (param_1 + 0x28,local_18,&local_14,&local_14);
    pbVar6 = (byte *)(uint)bVar4;
    switch(pbVar6) {
    case (byte *)0x0:
    case (byte *)0x1:
      pbVar6 = local_18;
      pbVar7 = local_18;
      if (pbVar6 < local_14) {
        do {
          puVar3 = *(undefined4 **)(param_1 + 0x24);
          bVar2 = *pbVar7;
          pbVar7 = pbVar7 + 1;
          iVar5 = FUN_004553d0((int)puVar3,-1);
          if (iVar5 < 0) {
            piVar1 = puVar3 + 0xb;
            iVar5 = *piVar1;
            *piVar1 = *piVar1 + -1;
            if (iVar5 == 0) {
              pbVar6 = (byte *)FUN_00455650((int)(char)bVar2,puVar3);
            }
            else {
              pbVar6 = (byte *)puVar3[10];
              puVar3[10] = puVar3[10] + 1;
              *pbVar6 = bVar2;
              pbVar6 = (byte *)(uint)*pbVar6;
            }
          }
          else {
            pbVar6 = (byte *)0xffffffff;
          }
          if (pbVar6 == (byte *)0xffffffff) {
            return 0xffffff00;
          }
        } while (pbVar7 < local_14);
      }
      break;
    case (byte *)0x2:
      return 0;
    }
    if (bVar4 != 1) {
      return CONCAT31((int3)((uint)pbVar6 >> 8),1);
    }
  } while( true );
}


