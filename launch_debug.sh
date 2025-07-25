SCRIPT_DIR=$( cd "$( dirname "$0" )" && pwd )
MAIN="$SCRIPT_DIR/bin/sibgamejam2025_linux_x64d"
export LD_LIBRARY_PATH="$SCRIPT_DIR/bin:$LD_LIBRARY_PATH"
if [ -f "$MAIN" ]; then
	 "$MAIN" -video_app auto -video_refresh 0 -video_debug 0 -main_window_size 2560 1440 -main_window_resizable 1 -main_window_fullscreen 0 -render_vsync 0 -video_offscreen 0 -sound_app auto -data_path ../data/ -extern_plugin UnigineFbxImporter,UnigineGLTFImporter,UnigineFbxExporter,UnigineUsdExchanger -console_command "config_autosave 0 && world_load \"sibgamejam2025\""
else
	echo "Application executable not found"
fi
