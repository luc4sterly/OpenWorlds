// 00441210 FUN_00441210 [Global]
// program: gamma.dll

void __thiscall FUN_00441210(int param_1,LPCSTR param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uStack_234;
  int *piStack_230;
  WCHAR aWStack_22c [260];
  int *piStack_24;
  int *piStack_20;
  int iStack_1c;
  int *piStack_18;
  char *pcStack_14;
  
  MultiByteToWideChar(0,0,param_2,-1,aWStack_22c,0x104);
  iVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0x38))
                    (*(int **)(param_1 + 0xc),aWStack_22c,u_SOURCE_004783e8,&piStack_230);
  if (iVar3 < 0) {
    FUN_0044d5a0(s_Could_not_create_source_filter_t_004783f8);
    FUN_0044d5a0(&DAT_004780c8);
    return;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x2c))
                    (*(int **)(param_1 + 0x1c),&DAT_00478424,&uStack_234);
  if (iVar3 < 0) {
    FUN_0044d5a0(s_Could_not_find_input_pin__0047842c);
    FUN_0044d5a0(&DAT_004780c8);
    return;
  }
  (**(code **)(*piStack_230 + 0x28))(piStack_230,&piStack_24);
  iVar3 = (**(code **)(*piStack_24 + 0xc))(piStack_24,1,&piStack_20,0);
  do {
    if (iVar3 != 0) {
      (**(code **)(*piStack_24 + 8))(piStack_24);
      iVar3 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                        (*(undefined4 **)(param_1 + 0xc),&DAT_00467198,param_1 + 0x10);
      if (iVar3 < 0) {
        FUN_0044d5a0(s_Could_not_get_media_control_inte_004784c8);
        FUN_0044d5a0(&DAT_004780c8);
        return;
      }
      iVar3 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                        (*(undefined4 **)(param_1 + 0xc),&DAT_00467178,param_1 + 0x14);
      if (-1 < iVar3) {
        iVar3 = (**(code **)**(undefined4 **)(param_1 + 0xc))
                          (*(undefined4 **)(param_1 + 0xc),&DAT_00467188,param_1 + 0x18);
        if (-1 < iVar3) {
          return;
        }
        FUN_0044d5a0(s_Could_not_get_media_event_interf_00478518);
        FUN_0044d5a0(&DAT_004780c8);
        return;
      }
      FUN_0044d5a0(s_Could_not_get_media_position_int_004784f0);
      FUN_0044d5a0(&DAT_004780c8);
      return;
    }
    (**(code **)(*piStack_20 + 0x24))(piStack_20,&iStack_1c);
    if (iStack_1c == 1) {
      iVar3 = (**(code **)(*piStack_20 + 0x30))(piStack_20,&piStack_18);
      if (iVar3 < 0) {
        FUN_0044d5a0(s_Could_not_enumerate_pin_types_00478448);
        FUN_0044d5a0(&DAT_004780c8);
        return;
      }
      iVar3 = (**(code **)(*piStack_18 + 0xc))(piStack_18,1,&pcStack_14,0);
      if (iVar3 < 0) {
        FUN_0044d5a0(s_Could_not_get_media_type_for_pin_00478468);
        FUN_0044d5a0(&DAT_004780c8);
        return;
      }
      iVar3 = 0x10;
      pcVar7 = pcStack_14;
      pcVar5 = &DAT_00477f2c;
      do {
        pcVar4 = pcVar7;
        pcVar6 = pcVar5;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        pcVar6 = pcVar5 + 1;
        pcVar4 = pcVar7 + 1;
        cVar2 = *pcVar5;
        cVar1 = *pcVar7;
        pcVar7 = pcVar4;
        pcVar5 = pcVar6;
      } while (cVar1 == cVar2);
      if (pcVar4[-1] == pcVar6[-1]) {
        iVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0x2c))
                          (*(int **)(param_1 + 0xc),piStack_20,uStack_234);
        if (iVar3 < 0) {
          pcVar7 = s_Failed_to_connect_video_pin__0047848c;
          goto LAB_004413d6;
        }
      }
      else {
        iVar3 = (**(code **)(**(int **)(param_1 + 0xc) + 0x30))(*(int **)(param_1 + 0xc),piStack_20)
        ;
        if (iVar3 < 0) {
          pcVar7 = s_Failed_to_render_audio_pin__004784ac;
LAB_004413d6:
          FUN_0044d5a0(pcVar7);
          FUN_0044d5a0(&DAT_004780c8);
        }
      }
      FUN_004483c0(pcStack_14);
    }
    (**(code **)(*piStack_20 + 8))(piStack_20);
    iVar3 = (**(code **)(*piStack_24 + 0xc))(piStack_24,1,&piStack_20,0);
  } while( true );
}


