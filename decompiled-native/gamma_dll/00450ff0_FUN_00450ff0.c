// 00450ff0 FUN_00450ff0 [Global]
// program: gamma.dll

void __cdecl FUN_00450ff0(int *param_1,int *param_2,ushort *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  char *pcVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  
  do {
    while (puVar2 = (ushort *)param_2[2], puVar2 == (ushort *)0x0) {
      pcVar3 = (char *)FUN_00450ee0(param_1,param_2);
      FUN_00450c70(pcVar3,param_2);
      if (*param_2 == 0) {
        FUN_00458ca0();
      }
    }
    uVar1 = *puVar2;
    switch(uVar1 & 0xff) {
    case 1:
      (**(code **)(puVar2 + 3))();
      param_2[2] = param_2[2] + 10;
      break;
    case 2:
      iVar5 = FUN_00450f30(param_1,*(uint *)(puVar2 + 5),1);
      if (iVar5 != 0) {
        (**(code **)(puVar2 + 3))();
      }
      param_2[2] = param_2[2] + 0xe;
      break;
    default:
      FUN_00458ca0();
      break;
    case 4:
      FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
      (**(code **)(puVar2 + 3))();
      param_2[2] = param_2[2] + 10;
      break;
    case 5:
      pcVar4 = *(code **)(puVar2 + 3);
      for (iVar5 = *(int *)(puVar2 + 5); 0 < iVar5; iVar5 = iVar5 + -1) {
        (*pcVar4)();
      }
      param_2[2] = param_2[2] + 0x12;
      break;
    case 6:
      FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
      iVar5 = FUN_00450f30(param_1,*(uint *)(puVar2 + 3),4);
      pcVar4 = (code *)FUN_00450f30(param_1,*(uint *)(puVar2 + 5),4);
      FUN_00450f30(param_1,*(uint *)(puVar2 + 7),4);
      for (; 0 < iVar5; iVar5 = iVar5 + -1) {
        (*pcVar4)();
      }
      param_2[2] = param_2[2] + 0x12;
      break;
    case 7:
      FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
      (**(code **)(puVar2 + 3))();
      param_2[2] = param_2[2] + 0xe;
      break;
    case 8:
      iVar5 = FUN_00450f30(param_1,*(uint *)(puVar2 + 3),2);
      if (iVar5 != 0) {
        FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
        (**(code **)(puVar2 + 5))();
      }
      param_2[2] = param_2[2] + 0x12;
      break;
    case 9:
      FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
      pcVar4 = *(code **)(puVar2 + 3);
      for (iVar5 = *(int *)(puVar2 + 7); 0 < iVar5; iVar5 = iVar5 + -1) {
        (*pcVar4)();
      }
      param_2[2] = param_2[2] + 0x16;
      break;
    case 10:
      iVar5 = FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
      (**(code **)(puVar2 + 3))(iVar5);
      param_2[2] = param_2[2] + 10;
      break;
    case 0xb:
      iVar5 = FUN_00450f30(param_1,*(uint *)(puVar2 + 5),1);
      if (iVar5 != 0) {
        iVar5 = FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
        (**(code **)(puVar2 + 3))(iVar5);
      }
      param_2[2] = param_2[2] + 0xe;
      break;
    case 0xc:
      FUN_00450f30(param_1,*(uint *)(puVar2 + 1),4);
      (**(code **)(puVar2 + 3))();
      param_2[2] = param_2[2] + 0xe;
      break;
    case 0x10:
      if (param_3 == puVar2) {
        return;
      }
      param_2[2] = param_2[2] + 0xe;
      break;
    case 0x11:
      piVar6 = (int *)(param_1[3] + *(int *)(puVar2 + 1));
      if (piVar6[2] != 0) {
        if (param_1[6] == *piVar6) {
          param_1[7] = piVar6[2];
        }
        else {
          (*(code *)piVar6[2])();
        }
      }
      param_2[2] = param_2[2] + 6;
      break;
    case 0x13:
      if (param_3 == puVar2) {
        return;
      }
      param_2[2] = param_2[2] + (uint)puVar2[1] * 4 + 0xc;
    }
    if ((uVar1 & 0x8000) != 0) {
      param_2[2] = 0;
    }
  } while( true );
}


