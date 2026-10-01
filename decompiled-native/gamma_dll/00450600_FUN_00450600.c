// 00450600 FUN_00450600 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00450600(int param_1)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte local_18 [4];
  byte *local_14;
  
  do {
    local_14 = local_18;
    bVar4 = (**(code **)(**(int **)(param_1 + 0x2c) + 0xc))
                      (param_1 + 0x28,local_18,&local_14,&local_14);
    pbVar5 = (byte *)(uint)bVar4;
    switch(pbVar5) {
    case (byte *)0x0:
    case (byte *)0x1:
      pbVar7 = local_18;
      pbVar5 = local_18;
      if (pbVar5 < local_14) {
        do {
          puVar3 = *(undefined4 **)(param_1 + 0x24);
          bVar2 = *pbVar7;
          pbVar7 = pbVar7 + 1;
          iVar6 = FUN_004553d0((int)puVar3,-1);
          if (iVar6 < 0) {
            piVar1 = puVar3 + 0xb;
            iVar6 = *piVar1;
            *piVar1 = *piVar1 + -1;
            if (iVar6 == 0) {
              pbVar5 = (byte *)FUN_00455650((int)(char)bVar2,puVar3);
            }
            else {
              pbVar5 = (byte *)puVar3[10];
              puVar3[10] = puVar3[10] + 1;
              *pbVar5 = bVar2;
              pbVar5 = (byte *)(uint)*pbVar5;
            }
          }
          else {
            pbVar5 = (byte *)0xffffffff;
          }
          if (pbVar5 == (byte *)0xffffffff) {
            return 0xffffff00;
          }
        } while (pbVar7 < local_14);
      }
      break;
    case (byte *)0x2:
      return 0;
    }
    if (bVar4 != 1) {
      return CONCAT31((int3)((uint)pbVar5 >> 8),1);
    }
  } while( true );
}


