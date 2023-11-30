import gpxpy
import gpxpy.gpx

gpx_file = open('test.gpx', 'r')


writer = open("parcours.csv","w")
gpx = gpxpy.parse(gpx_file)
for track in gpx.tracks:
    for segment in track.segments:
        for point in segment.points:
            writer.write(f"{point.latitude},{point.longitude},{point.elevation},0\n")
writer.close()



