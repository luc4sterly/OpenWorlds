// 00417250 _Java_NET_worlds_scape_Material_paramChange@8 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Java_NET_worlds_scape_Material_paramChange_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  
                    /* 0x17250  254  _Java_NET_worlds_scape_Material_paramChange@8 */
  iVar3 = (**(code **)(*param_1 + 0x17c))(param_1,param_2,DAT_0049fa08);
  if (iVar3 != 0) {
    iVar4 = (**(code **)(*param_1 + 0x2ac))(param_1,iVar3);
    iVar5 = (**(code **)(*param_1 + 0x2ec))(param_1,iVar3,0);
    iVar9 = 0;
    if (0 < iVar4) {
      do {
        uVar1 = *(undefined4 *)(iVar5 + iVar9 * 4);
        fVar10 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049fce4);
        fVar11 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049fa00);
        fVar12 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049fce8);
        FUN_00419ef0(uVar1,(float)fVar12,(float)fVar11,(float)fVar10);
        iVar6 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb9c);
        iVar7 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb94);
        iVar8 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb8c);
        FUN_00419e90(uVar1,(float)iVar8 * _DAT_004701cc,(float)iVar7 * _DAT_004701cc,
                     (float)iVar6 * _DAT_004701cc);
        fVar10 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049ff48);
        FUN_00419ec0(uVar1,(float)fVar10);
        cVar2 = (**(code **)(*param_1 + 0x180))(param_1,param_2,DAT_0049ff5c);
        if (cVar2 == '\0') {
          FUN_00417950(uVar1);
        }
        else {
          FUN_00417a10(uVar1);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < iVar4);
    }
    (**(code **)(*param_1 + 0x30c))(param_1,iVar3,iVar5,0);
  }
  return;
}


