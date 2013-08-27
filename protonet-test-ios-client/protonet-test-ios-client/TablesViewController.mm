//
//  JoinViewController.m
//  poker-hand
//
//  Created by Alexey Kuznetsov on 08/07/2013.
//  Copyright (c) 2013 Alexey Kuznetsov. All rights reserved.
//

#import "TablesViewController.h"
#import "ProtoNetDiscovery.h"
#import "JoinViewController.h"
#include <arpa/inet.h>
#import "SocketHandler.h"

@interface TablesViewController ()

@end

@implementation TablesViewController

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
    
    AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
    [[appDelegate discovery] setDelegate: self];
    [[appDelegate socket] disconnect];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
    return [appDelegate discovery].services.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"PokerTableCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier forIndexPath:indexPath];
    
    AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];

    ProtoNetDiscoveryService* s = [[appDelegate discovery].services objectAtIndex: indexPath.row];
    
    cell.textLabel.text = [NSString stringWithFormat:@"%@:%d", s.address, s.port];
    
    return cell;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    /*
     When a row is selected, the segue creates the detail view controller as the destination.
     Set the detail view controller's detail item to the item associated with the selected row.
     */
    if ([[segue identifier] isEqualToString:@"TablesJoinSegue"]) {
        NSIndexPath *selectedRowIndex = [self.tableView indexPathForSelectedRow];
        JoinViewController *join = [segue destinationViewController];

        AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];

        ProtoNetDiscoveryService* s = [[appDelegate discovery].services objectAtIndex: selectedRowIndex.row];

        join.host = s.address;
        join.port = s.port;
    }
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:@[indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     */
}

- (void)addService:(ProtoNetDiscoveryService*)s moreComing:(bool)moreComing;
{
    [self.tableView reloadData];
}

- (void)removeService:(ProtoNetDiscoveryService*)s moreComing:(bool)moreComing;
{
    [self.tableView reloadData];
}

@end
