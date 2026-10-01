// 004219e0 _Java_NET_worlds_scape_ScapePicTexture_nativeInit@8 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_ScapePicTexture_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x219e0  282  _Java_NET_worlds_scape_ScapePicTexture_nativeInit@8 */
  if (DAT_0049d188 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_ScapePicTexture_004713a0);
    DAT_0049d188 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_0049d188 == 0) {
      FUN_00402800(s_nScapePicTexture_004713c4,0x56);
    }
    DAT_0049d190 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d188,s_textureID_004713dc,&DAT_004713d8);
    DAT_0049d194 = (**(code **)(*param_1 + 0x178))(param_1,DAT_0049d188,&DAT_004713e8,&DAT_004713d8)
    ;
    DAT_0049d198 = (**(code **)(*param_1 + 0x178))(param_1,DAT_0049d188,&DAT_004713ec,&DAT_004713d8)
    ;
    DAT_0049d19c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d188,s__movie_00471414,
                              s_LNET_worlds_scape_ScapePicMovie__004713f0);
    DAT_0049d1a0 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d188,s__movieFrame_0047141c,&DAT_004713d8);
    DAT_0049d1bc = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049d188,s_<init>_0047142c,&DAT_00471428);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049d190 != 0) && (DAT_0049d194 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049d198 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nScapePicTexture_004713c4,0x62);
    }
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049d19c != 0) && (DAT_0049d1a0 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049d1bc != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nScapePicTexture_004713c4,99);
    }
  }
  return;
}


