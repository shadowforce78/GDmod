cls
@echo off
echo "Stopping Geometry Dash...."
@echo off
taskkill /f /im GeometryDash.exe
echo "Geometry Dash stopped!"
echo "Starting build...."
cmake --build build --config RelWithDebInfo
echo "Build complete!"
echo "Starting Geometry Dash...."
start steam://rungameid/322170
echo "Geometry Dash started!"
