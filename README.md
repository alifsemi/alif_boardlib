# boardlib_DEV

BOARD support library for Alif Application Kits and Alif Development Kits

## Development Boards Supported

This board library has been tested on the following evaluation platforms.
- Alif Development Kit BASE-BOARD with
  - Silicon Rev A1/A6 CPU-CARD (BGA)
  - Silicon Rev B0 CPU-CARD (COB board)
- Alif AI/ML Application Kit in Alpha1 and Alpha2 revisions
- Alif Development Kit with Silicon Rev B0 (flatboard)

## Adding boardlib to a project in Arm-DS

1. Select the project in the left-hand project explorer, and right-click.
2. Select New -> Folder
3. Click Advanced >> and then select the 3rd option: Link to alternate location
4. Click Browse... and then select the 'boardlib_DEV' folder that you cloned
5. Rename 'Folder name:' to simply 'board' and click Finish
6. Copy board_template.h from 'board' folder to the root of the project
7. Rename the board_template.h to board.h
8. Open and change #if 0 to 1 and change BOARD_ALIF_DEVKIT_VARIANT to match your board
9. Add the below include folder paths in Project properties
    1. /${ProjName}/
    2. /${ProjName}/board
10. You're done!

## Dependencies

Support for the Silicon Rev B0 CPU-CARD (COB board) requres additional steps. Please visit [B0 CMSIS bringup](https://alifsemi.atlassian.net/l/cp/F7kMD1SF) page.
