// 00451490 FUN_00451490 [Global]
// programa: gamma.dll

void FUN_00451490(int *param_1)

{
  ushort *puVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_34;
  undefined4 local_30;
  ushort *local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  ushort *local_18;
  int local_14;
  
  FUN_00450c70((char *)param_1[4],&local_20);
  if (local_20 == 0) {
    FUN_00458ca0();
  }
  if (param_1[5] == 0) {
    local_34 = local_20;
    local_30 = local_1c;
    local_2c = local_18;
    local_24 = 0;
    local_28 = param_1[3];
    uVar2 = FUN_00450df0((int)&local_34);
    do {
      switch(uVar2) {
      case 0:
      case 1:
      case 2:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0x10:
      case 0x13:
        uVar2 = FUN_00450e10(&local_34);
        break;
      default:
        FUN_00458ca0();
      case 0x11:
        goto switchD_004514f7_caseD_11;
      }
    } while( true );
  }
  param_1[8] = 0;
LAB_00451541:
  local_34 = local_20;
  local_30 = local_1c;
  local_2c = local_18;
  local_24 = 0;
  local_28 = param_1[3];
  uVar2 = FUN_00450df0((int)&local_34);
  do {
    switch(uVar2) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0x11:
      break;
    default:
      FUN_00458ca0();
LAB_004515e1:
      puVar1 = local_2c;
      FUN_00450ff0(param_1,&local_20,local_2c);
      piVar5 = (int *)(param_1[3] + *(int *)(puVar1 + 5));
      *piVar5 = param_1[6];
      piVar5[1] = param_1[5];
      piVar5[2] = param_1[7];
      if (*(char *)param_1[5] == '*') {
        piVar5[3] = (int)(piVar5 + 4);
        piVar5[4] = *(int *)param_1[6] + local_14;
      }
      else {
        piVar5[3] = param_1[6] + local_14;
      }
                    /* WARNING: Could not recover jumptable at 0x0045165c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(puVar1 + 3))();
      return;
    case 0x10:
      uVar3 = FUN_00458cc0((char *)param_1[5],*(char **)(local_2c + 1),&local_14);
      if ((char)uVar3 != '\0') goto LAB_004515e1;
      break;
    case 0x13:
      iVar4 = FUN_00451330((char *)param_1[5],(int)local_2c);
      if (iVar4 == 0) {
        FUN_00451410(param_1,&local_20,local_2c);
      }
    }
    uVar2 = FUN_00450e10(&local_34);
  } while( true );
switchD_004514f7_caseD_11:
  piVar5 = (int *)(local_28 + *(int *)(local_2c + 1));
  param_1[5] = piVar5[1];
  param_1[6] = *piVar5;
  param_1[7] = 0;
  param_1[8] = (int)piVar5;
  goto LAB_00451541;
}


