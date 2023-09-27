# BoardLib

BOARD support library for Alif Semiconductor Development and Application Kits

## Development Boards Supported

This board library has been tested on the following evaluation platforms.
- Generation 1 Development Kit
- Generation 1 AI/ML Application Kit (Alpha1 and Alpha2 revisions)
- Generation 2 Development Kit
- Generation 2 AI/ML Application Kit

For most of the application projects, the board library is a submodule and will be part of the project once *submodule init* and *submodule update* is done.

To manually add the board library to the ARM DS project please follow the instructions below. Similar steps need to be followed for other environments.

## Manually Adding boardlib to a project in Arm-DS

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
